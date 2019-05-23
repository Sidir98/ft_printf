/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 10:14:36 by ibouabda          #+#    #+#             */
/*   Updated: 2019/05/15 18:14:20 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	if (str == NULL)
		return 0;
	max = ft_strlen((char*)to_find);
	if (max <= 0)
		return (0);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (j == max)
				return (&((char*)str)[i]);
		}
		i++;
	}
	return (0);
}