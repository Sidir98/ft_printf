/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:40:50 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/05 11:20:28 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2dstrdel(char **as)
{
	size_t i;

	i = 0;
	if (as != NULL)
	{
		while (as[i])
		{
			free(as[i]);
			i++;
		}
		free(as);
		as = NULL;
	}
}
