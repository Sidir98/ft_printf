/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3dstrnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:51:45 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/05 11:56:08 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	***ft_3dstrnew(size_t size)
{
	char	***str;
	size_t	i;

	i = 0;
	if (!(str = (char***)malloc(sizeof(char**) * (size + 1))))
	{
		ft_putendl("ft_3dstrnew malloc error");
		exit(EXIT_FAILURE);
	}
	while (i < (size + 1))
	{
		str[i] = NULL;
		i++;
	}
	return (str);
}
