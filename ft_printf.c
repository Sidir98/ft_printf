/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:32:42 by ibouabda          #+#    #+#             */
/*   Updated: 2019/05/27 16:51:49 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int di(int nb)
{
	int i;

	i = 1;
	ft_putnbr_count(nb, &i);
	return (i);
}

int u(int nb)
{
	int i;

	i = 1;
	ft_putnbr_count(ABS(nb), &i);
	return (i);
}

int o(int nb)
{
	int i;
	char * str;

	i = 0;
	str = ft_strnew(10);
	while (nb >= 8)
	{
		str[i] = ('0' + (nb % 8));
		nb = nb / 8;
		i++;
	}
	str[i] = '0' + nb;
	i++;
	str[i] = '\0';
	ft_putstr(ft_strrev(str));
	return (i);
}

void ft_puthex(int nb,char *base, int *i)
{
	if (nb >= 16)
	{
		*i += 1;
		ft_puthex(nb / 16,base, i);
	}
	ft_putchar(base[nb % 16]);
}

int x(int nb)
{
	int i;

	i = 1;
	char *base;

	base = "0123456789abcdef";
	ft_puthex(nb,base, &i);
	return(i);
}

int X(int nb)
{
	int i;

	i = 1;
	char *base;

	base = "0123456789ABCDEF";
	ft_puthex(nb,base, &i);
	return(i);
}

int c(int c)
{
	ft_putchar(c);
	return (1);
}

int s(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int p (void *ptr)
{
	return(s(ft_itoa((int)ptr)));
}

/*t_f *ft_newt_f(char c, fptr f)
{
	t_f *newf;

	if (!(newf = (t_f *)malloc(sizeof(t_f))))
		return (NULL);
	if (f == NULL)
		newf->ft = NULL;
	else
		newf->ft = f;
	
	return newf;
}*/

t_list *initialize_lst()
{
	t_list *m;

	m = ft_lstnew(m, 'd');
	ft_lstaddend(&m, ft_lstnew(&di, 'i'));
	ft_lstaddend(&m, ft_lstnew(&o, 'o'));
	ft_lstaddend(&m, ft_lstnew(&u, 'u'));
	ft_lstaddend(&m, ft_lstnew(&x, 'x'));
	ft_lstaddend(&m, ft_lstnew(&X, 'X'));
	ft_lstaddend(&m, ft_lstnew(&c, 'c'));
	ft_lstaddend(&m, ft_lstnew(&s, 's'));
	ft_lstaddend(&m, ft_lstnew(&p, 'p'));
	return (m);
}

int spe_out(va_list args, t_list *m, char c)
{
	while (m->content_size != c && m->next != NULL)
		m = m->next;
	if (m != NULL)
	{
		if (m->content_size == 'p')
			return (((int (*)(void*))m->content)(va_arg(args, char*)));
		if (m->content_size == 's')
			return (((int (*)(char*))m->content)(va_arg(args, char*)));
		return (((int (*)(int))m->content)(va_arg(args, int)));
	}
	return (0);
}

int ft_printf(char *str, ...)
{
	va_list args;
	t_list *m;
	int i;
	int count;
	int (*f) (int);


	i = 0;
	count = 0;
	if (str == NULL)
	{
		ft_putstr("Error no arguments\n");
		return (-1);
	}
	m = initialize_lst();
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += spe_out(args, m, str[i + 1]) - 2;
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (i + count);
}

int main()
{
	int i;
	int k;
	char *str;

	str = "lol";
	i = ft_printf("Ceci est un pointeur %p\n", str);
	k = printf("Ceci est un pointeur %p\n", str);
	printf("My equal to %i\n", i);
	printf("Official equal to %i\n", k);
}