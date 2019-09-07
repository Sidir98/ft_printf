/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:28:08 by ibouabda          #+#    #+#             */
/*   Updated: 2019/07/15 14:01:42 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchar(int nb, char c)
{
	char	*dest;
	int		i;

	dest = ft_strnew(nb);
	i = 0;
	while (i < nb)
	{
		dest[i] = c;
		i++;
	}
	return (dest);
}