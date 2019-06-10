/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 16:37:15 by ibouabda          #+#    #+#             */
/*   Updated: 2019/06/10 17:41:29 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putdouble(int n, int *i)
{
	int tmp;

	//printf("i = %i\n", *i);
	if (n < 0)
	{
		ft_putchar('-');
		tmp = -n;
		*i += 1;
	}
	else
		tmp = n;
	if (tmp >= 10)
	{
		ft_putdouble(tmp / 10, i);
		*i += 1;
	}
	ft_putchar('0' + (int)tmp % 10);
	if (*i == 6)
		ft_putchar('.');
}
