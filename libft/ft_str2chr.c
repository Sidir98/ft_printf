/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:02:26 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/09 13:21:49 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str2chr(char *src, char *to_find)
{
	int i;

	i = 0;
	while (src[i])
	{
		if (ft_strchr(to_find, src[i]))
			return(src + i);
		i++;
	}
	return (NULL);
}