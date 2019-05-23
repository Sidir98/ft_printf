/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:31:42 by ibouabda          #+#    #+#             */
/*   Updated: 2018/11/16 11:22:01 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *src, int c, size_t n)
{
	int i;

	i = 0;
	while (i < (int)n)
	{
		((char *)src)[i] = (char)c;
		i++;
	}
	return (src);
}
