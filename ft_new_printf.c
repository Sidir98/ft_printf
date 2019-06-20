/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:50:22 by ibouabda          #+#    #+#             */
/*   Updated: 2019/06/20 17:50:39 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *u(int nb)
{
	return(ft_itoa(ABS(nb)));
}

char *o(int nb)
{
	return(ft_itoa_base(nb, 8));
}

char *x(int nb)
{
	return(ft_itoa_base(nb, 16));
}

char	*X(int nb)
{
	return(ft_itoa_base_maj(nb, 16));
}

char *c(int c)
{
	char *str;

	str = ft_strnew(1);
	str[0] = c;
	return(str);

}

char *p(void *ptr)
{
	return(ft_strjoin("0x", ft_itoa_base((int)ptr, 16)));

}

int arrondi(double nb, int b)
{
	int i;
	int m;
	int anb;

	i = 0;
	m = 10;
	while (i < b)
	{
		m = m * 10;
		i++;
	}
	anb = nb;
	nb = nb - anb;
	anb = nb * m;
	if (anb % 10 >= 5)
	{
		anb = anb / 10;
		anb++;
	}
	else
		anb = anb / 10;
	return (anb);
}

char *f(double nb, int numbers) //ajouter precision variable
{
	int i;
	int mod;
	int nbcast;
	char *ints;
	char *floats;
	char *todel;

	i = 0;
	nbcast = nb;
	ints = ft_itoa(nbcast);
	if (nb < 0)
		nb = -nb;
	nbcast = arrondi(nb, numbers);
	mod = ft_countnumbers(nbcast);
	floats = ft_strnew(numbers + 1);
	floats[0] = '.';
	while (i < numbers - mod)
	{
		floats[i] = '0';
		i++;
	}
	todel = ft_strjoin(floats, ft_itoa(nbcast));
	floats = ft_strjoin(ints,todel);
	free(ints);
	free(todel);
	return (floats);
}

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
	ft_lstaddend(&m, ft_lstnew(NULL, 's'));
	ft_lstaddend(&m, ft_lstnew(&p, 'p'));
	ft_lstaddend(&m, ft_lstnew(&f, 'f'));
	return (m);
}

int spe_out(va_list args, t_list *m, char *str)
{
	int i;
	int precs;
	char *toprint;

	precs = 6;
	i = 0;
	/*if (str[i] > '0' && str[i] <= '9')
	{
		nb = ft_atoi(str);
		while (i < nb)
		{
			ft_putchar(' ');
			i++;
		}
		i = ft_countnumbers(nb);
	}*/
	while (m->content_size != (size_t)str[i] && m->next != NULL)
		m = m->next;
	if (m != NULL)
	{
		if (m->content_size == 'f')
			ft_strjoin(toprint,(((char *(*)(double, int))m->content)(va_arg(args, double), precs)));
		if (m->content_size == 'p')
			ft_strjoin(toprint, (((char *(*)(void *))m->content)(va_arg(args, void *))));
		if (m->content_size == 's')
			ft_strjoin(toprint, va_arg(args, char*));
		ft_strjoin(toprint, (((char *(*)(int))m->content)(va_arg(args, int))));
	}
	ft_putstr(toprint);
	return (ft_strlen(toprint));
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
		ft_putchar(str[i + k]);
		i++;
	}
	va_end(args);
	return (i + count);
}

int main()
{
	char *str;
	double d;
	int nb;

	str = "loldd";
	//i = ft_printf("Ceci est un double %f\n", -477.2477777);
	//k = printf("Ceci est un double %i\n", 477);
	//printf("My equal to %i\n", i);
	//printf("Official equal to %i\n", k);
	d = 3669.5358;
	nb = d;
	printf("d = %f, nb = %i, d - nb = %f123 \n", d, nb, d - (d - nb));
}