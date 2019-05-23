/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 21:23:41 by ibouabda          #+#    #+#             */
/*   Updated: 2018/11/05 22:08:29 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	a;

	a = 1;
	while (a * a < nb && nb <= 2147395600)
		a++;
	if (a * a == nb)
		return (a);
	else
		return (0);
}