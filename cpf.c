/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:02:16 by ibouabda          #+#    #+#             */
/*   Updated: 2019/07/15 19:06:35 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *c(int c)
{
	char *str;

	str = ft_strnew(1);
	str[0] = c;
	return(str);

}

char *p(void *ptr)
{
	char *todel;
	char *toreturn;

	todel = ft_itoa_base((int)ptr, 16);
	toreturn = ft_strjoin("0x",todel);
	ft_strdel(&todel);
	return(toreturn);
}

int arrondi(double nb, int b)
{
	int i;
	long long int m;
	long long int anb;

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

char *f(double nb, int precs)
{
	int i;
	int mod;
	long long int nbcast;
	char *ints;
	char *floats;
	char *todel;
	char *todel2;

	i = 0;
	nbcast = nb;
	ints = ft_itoa(nbcast);
	if (nb < 0)
		nb = -nb;
	nbcast = arrondi(nb, precs);
	mod = ft_countnumbers(nbcast);
	floats = ft_strnew(precs + 1);
	floats[0] = '.';
	while (i < precs - mod)
	{
		floats[i + 1] = '0';
		i++;
	}
	todel = floats;
	todel2 = ft_itoa(nbcast);
	floats = ft_strjoin(todel, todel2);
	ft_strdel(&todel);
	ft_strdel(&todel2);
	todel = floats;
	floats = ft_strjoin(ints, todel);
	ft_strdel(&ints);
	ft_strdel(&todel);
	return (floats);
}