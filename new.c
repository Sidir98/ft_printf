/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:08:12 by ibouabda          #+#    #+#             */
/*   Updated: 2019/05/20 16:32:40 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

void ft_put_until(char *str, char *s)
{
	int i;

	i = 0;
	while (str + i != s && str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void write_int(char **str, char **i, va_list args)
{
	ft_put_until(*str, *i);
	ft_putnbr(va_arg(args, int));
	*i = *i + 2;
	*str = *i;
	*i = ft_strstr(*str, "%i");
}

void write_string(char **str, char **s, va_list args)
{
	ft_put_until(*str, *s);
	ft_putstr(va_arg(args, char*));
	*s = *s + 2;
	*str = *s;
	*s = ft_strstr(*str, "%s");
}

void ft_printf(char *str, ...)
{
	va_list args;
	int count;
	char *s;
	char *i;

	if (str == NULL)
	{
		ft_putstr("Error no arguments\n");
		return;
	}
	va_start(args, str);
	i = ft_strstr(str, "%i");
	s = ft_strstr(str, "%s");
	while ((i != 0) || (s != 0))
	{
		if ((i < s && i != 0) || ( s == 0 && i != 0))
			write_int(&str, &i, args);
		else if ((s < i && s != 0) || (i == 0 && s != 0))
			write_string(&str, &s, args);
	}
	if (str[0])
		ft_putstr(str);
	va_end(args);
}

int main(int argc, char **argv)
{
	char	*str;

	str = "heho";
	ft_printf("je suis a %i %s %s", 42, "allo", str);
	return (0);
}