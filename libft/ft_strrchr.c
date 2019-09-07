/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:55:54 by ibouabda          #+#    #+#             */
/*   Updated: 2018/11/17 16:07:35 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	char	*mysrc;
	char	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	mysrc = (char*)src;
	while (mysrc[i] != '\0')
	{
		if (mysrc[i] == c)
		{
			ptr = &mysrc[i];
		}
		i++;
	}
	if (mysrc[i] == c)
	{
		ptr = &mysrc[i];
	}
	return (ptr);
}
