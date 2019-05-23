/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:19:57 by ibouabda          #+#    #+#             */
/*   Updated: 2018/11/26 16:22:28 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *mys1;
	char *mys2;
	char *dest;

	if (s1 && s2)
	{
		mys1 = (char *)s1;
		mys2 = (char *)s2;
		if (!(dest = ft_strnew(ft_strlen(mys1) + ft_strlen(mys2))))
			return (NULL);
		return (ft_strcat(ft_strcpy(dest, mys1), mys2));
	}
	return (NULL);
}
