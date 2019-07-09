/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:50:22 by ibouabda          #+#    #+#             */
/*   Updated: 2019/07/09 16:32:42 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list *initialize_lst()
{
	t_list *m;

	m = ft_lstnew(&ft_itoa, 'd');
	ft_lstaddend(&m, ft_lstnew(&ft_itoa, 'i'));
	ft_lstaddend(&m, ft_lstnew(&o, 'o'));
	ft_lstaddend(&m, ft_lstnew(&u, 'u'));
	ft_lstaddend(&m, ft_lstnew(&x, 'x'));
	ft_lstaddend(&m, ft_lstnew(&X, 'X'));
	ft_lstaddend(&m, ft_lstnew(&c, 'c'));
	ft_lstaddend(&m, ft_lstnew(&s, 's'));
	ft_lstaddend(&m, ft_lstnew(&f, 'f'));
	ft_lstaddend(&m, ft_lstnew(&p, 'p'));
	return (m);
}

int spe_out(va_list args, t_list *m, char *str)
{
	int i;
	int size;
	int precs;
	char *toprint;
	int nb;

	precs = 6;
	size = 0;
	i = 0;
	nb = 0;
	if (str[size] > '0' && str[size] <= '9')
	{
		nb = ft_atoi(str);
		size = ft_countnumbers(nb);
	}
	//printf("size : %i\n", size);
	//printf("size : %c\n", str[size]);
	while ((int)(m->content_size) != str[size] && m->next)
		m = m->next;
	if ((int)(m->content_size) == str[size])
	{
		//printf("letter : %c, trueletter : %c", (int)m->content_size, str[size]);
		if ((int)m->content_size == 'f')
			toprint = (((char *(*)(double, int))m->content)(va_arg(args, double), precs));
		else if ((int)m->content_size == 'p')
			toprint = (((char *(*)(void *))m->content)(va_arg(args, void *)));
		else if ((int)m->content_size == 's')
			toprint = (((char *(*)(char *))m->content)(va_arg(args, char*)));
		else
			toprint = (((char *(*)(int))m->content)(va_arg(args, int)));
	}
	while (i < (nb - (int)ft_strlen(toprint)))
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(toprint);
	return (ft_strlen(toprint) + nb);
}

int ft_printf(char *str, ...)
{
	va_list args;
	t_list *m;
	int i;
	int k;
	int count;

	i = 0;
	count = 0;
	k = 0;
	if (str == NULL)
	{
		ft_putstr("Error no arguments\n");
		return (-1);
	}
	m = initialize_lst();
	va_start(args, str);
	while (str[i + k])
	{
		if (str[i + k] == '%')
		{
			k++;
			count += spe_out(args, m, str + i + k);
			while (!ft_strchr("%cspdiouxXf", str[i + k]))
				k++;
		}
		else
			ft_putchar(str[i + k]);
		i++;
	}
	va_end(args);
	return (i + count);
}

int main()
{
	char *str;
	int i;
	int k;

	str = "loldd";
	i = ft_printf("Ceci est un test %400s\n", "Heeeeeeee Bernard");
	k = printf("Ceci est un test %400s\n", "Heeeeeeee Bernard");
	//printf("My equal to %i\n", i);
	//printf("Official equal to %i\n", k);
}