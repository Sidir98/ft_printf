/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstrdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 09:57:10 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/09 11:32:02 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnstrdup(char *str, char *to_find, size_t n, char **stock)
{
	if (ft_strnstr(str, to_find, n))
	{
		*stock = ft_strdup(to_find);
		return (1);
	}
	return (0);
}