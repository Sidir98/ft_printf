/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:54:19 by ibouabda          #+#    #+#             */
/*   Updated: 2018/11/26 16:24:19 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*render;

	if (s && f)
	{
		i = 0;
		if (!(render = ft_strdup(s)))
			return (NULL);
		while (render[i] != '\0')
		{
			render[i] = f(i, render[i]);
			i++;
		}
		return (render);
	}
	return (NULL);
}
