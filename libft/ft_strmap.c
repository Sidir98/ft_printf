/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:05:53 by ibouabda          #+#    #+#             */
/*   Updated: 2018/11/26 16:23:47 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*render;

	if (s && f)
	{
		i = 0;
		if (!(render = ft_strdup(s)))
			return (NULL);
		while (render[i] != '\0')
		{
			render[i] = f(render[i]);
			i++;
		}
		if (render != NULL)
			return (render);
	}
	return (NULL);
}
