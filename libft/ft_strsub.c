/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:11:26 by ibouabda          #+#    #+#             */
/*   Updated: 2018/11/26 14:30:17 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *d;

	if ((int)len < 0 || s == NULL)
		return (NULL);
	if (!(d = ft_strnew(len)))
		return (NULL);
	d = ft_strncpy(d, &((char*)s)[start], len);
	d[len] = '\0';
	return (d);
}
