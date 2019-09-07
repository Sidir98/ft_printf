/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:52:51 by ibouabda          #+#    #+#             */
/*   Updated: 2018/11/24 17:32:52 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char			*mysrc;
	unsigned char			myc;

	mysrc = (unsigned char*)src;
	myc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (mysrc[i] == myc)
			return (&mysrc[i]);
		i++;
	}
	return (NULL);
}
