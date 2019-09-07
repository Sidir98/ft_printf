/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:02:16 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/07 17:05:55 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *c(int c) //char * de la lettre
{
	char *str;

	str = ft_strnew(1);
	str[0] = c;
	return(str);

}

char *p(void *ptr) // char * du pointeur
{
	char *todel;
	char *toreturn;

	todel = ft_itoa_base((int)ptr, 16);
	toreturn = ft_strjoin("0x",todel);
	ft_strdel(&todel);
	return(toreturn);
}

int arrondi(double nb, int b) //gere l'arrondi
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
void manage_str(char **ints, char **floats, int nbcast) //permet de transformer le double en un char *
{
	char *todel;
	char *todel2;

	todel2 = ft_itoa(nbcast);
	todel = *floats;
	*floats = ft_strjoin(todel, todel2);
	ft_strdel(&todel);
	ft_strdel(&todel2);
	todel = *floats;
	*floats = ft_strjoin(*ints, todel);
	ft_strdel(ints);
	ft_strdel(&todel);
}
char *f(double nb, int precs) // char * du type double
{
	int i;
	int mod;
	long long int nbcast;
	char *ints;
	char *floats;

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
	manage_str(&ints, &floats, nbcast);
	return (floats);
}