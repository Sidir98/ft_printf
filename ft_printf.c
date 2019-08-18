/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:50:22 by ibouabda          #+#    #+#             */
/*   Updated: 2019/07/16 16:39:50 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list *initialize_lst()
{
	t_list *m;

	m = ft_lstnewc(&ft_itoa, 'd');
	ft_lstaddend(&m, ft_lstnewc(&ft_itoa, 'i'));
	ft_lstaddend(&m, ft_lstnewc(&o, 'o'));
	ft_lstaddend(&m, ft_lstnewc(&u, 'u'));
	ft_lstaddend(&m, ft_lstnewc(&x, 'x'));
	ft_lstaddend(&m, ft_lstnewc(&X, 'X'));
	ft_lstaddend(&m, ft_lstnewc(&c, 'c'));
	ft_lstaddend(&m, ft_lstnewc(NULL, 's'));
	ft_lstaddend(&m, ft_lstnewc(&f, 'f'));
	ft_lstaddend(&m, ft_lstnewc(&p, 'p'));
	ft_lstaddend(&m, ft_lstnewc(NULL, '%'));
	return (m);
}

char *spe_search(va_list args, t_list *m, char *str, int precs)
{
	while ((int)(m->content_size) != str[0] && m->next)
		m = m->next;
	if ((int)(m->content_size) == str[0])
	{
		printf("ok");
		if ((int)m->content_size == 'f')
			return (((char *(*)(double, int))m->content)\
			(va_arg(args, double), precs));
		else if ((int)m->content_size == 'p')
			return (((char *(*)(void *))m->content)(va_arg(args, void *)));
		else if ((int)m->content_size == 's')
			return (ft_strdup(va_arg(args, char *)));
		else if ((int)m->content_size == '%')
			return ("%");
		else
			return ((((char *(*)(int))m->content)(va_arg(args, int))));
	}
	return (NULL);
}

void spe_input(char **str, int *nbl, int *nbp, int *precs)
{
	*precs = 6;
	*nbl = 0;
	*nbp = 0;
	if (**str > '0' && **str <= '9')
	{
		*nbl = ft_atoi(*str);
		*str += ft_countnumbers(*nbl);
	}
	if (**str == '.')
	{
		*str = *str + 1;
		*nbp = ft_atoi(*str);
		*str += ft_countnumbers(*nbp);
		*precs = *nbp;
	}
}
void modify_toprint(char **str, int *nbl, int *nbp, char **toprint)
{
	char *todel;
	char *todel2;

	if (*nbp > 0 && *nbp < (int)ft_strlen(*toprint) && **str == 's')
		*toprint[*nbp] = '\0';
	if (ft_strchr("diouxX", **str) && *nbp > 0 && *nbp > \
	(int)ft_strlen(*toprint))
	{
		todel = *toprint;
		todel2 = ft_strchar(*nbp - ft_strlen(todel), '0');
		*toprint = ft_strjoin(todel2, todel);
		ft_strdel(&todel);
		ft_strdel(&todel2);
	}
	if (0 < (*nbl - (int)ft_strlen(*toprint)))
	{
		todel = *toprint;
		todel2 = ft_strchar(*nbl - ft_strlen(todel), ' ');
		*toprint = ft_strjoin(todel2, todel);
		ft_strdel(&todel);
		ft_strdel(&todel2);
	}
}
int spe_out(va_list args, t_list *m, char *str)
{
	int precs;
	char *toprint;
	int nbl;
	int nbp;

	spe_input(&str, &nbl, &nbp, &precs);
	if (!(toprint = spe_search(args, m, str, precs)))
	{
		ft_putstr("Bad argument");
		exit(0);
	}
	modify_toprint(&str, &nbl, &nbp, &toprint);
	ft_putstr(toprint);
	nbp = ft_strlen(toprint);
	ft_strdel(&toprint);
	return (nbp);
}

t_list *initialize(int *i, int *k, int *count, char *str)
{
	*i = 0;
	*count = 0;
	*k = 0;
	if (str == NULL)
	{
		ft_putstr("Error no arguments\n");
		exit(0);
	}
	else
		return (initialize_lst());
}

int ft_printf(char *str, ...)
{
	va_list args;
	t_list *m;
	int i;
	int k;
	int count;

	m = initialize(&i, &k, &count, str);
	va_start(args, str);
	while (str[i + k])
	{
		if (str[i + k] == '%')
		{
			i--;
			k += 2;
			count += spe_out(args, m, str + i + k);
			while (!ft_strchr("%cspdiouxXf", str[i + k]))
				k++;
		}
		else
			ft_putchar(str[i + k]);
		i++;
	}
	va_end(args);
	ft_lstdelm(&m);
	return (i + count);
}

int main()
{
	char *str;
	int i;
	int k;

	str = "loldd";
	i = ft_printf(",. %i %f\n", 1, 2.123456);
	k = printf("'. %i %f\n", 1, 2.123456);
	printf("My equal to %i\n", i);
	printf("Official equal to %i\n", k);
	return (0);
}