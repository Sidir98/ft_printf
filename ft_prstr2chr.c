/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prstr2chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:15:08 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/09 13:43:14 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prstr2chr(char *src, char *to_find)
{
	int i;

	i = 0;
	while (src[i] && src[i] != ' ')
	{
		if (ft_strchr(to_find, src[i]))
			return(i);
		i++;
	}
	return (-1);
}