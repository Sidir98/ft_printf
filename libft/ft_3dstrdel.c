/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3dstrdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:32:10 by ibouabda          #+#    #+#             */
/*   Updated: 2019/04/08 14:22:20 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_3dstrdel(char ***tetrim)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	while (tetrim[i])
	{
		while (tetrim[i][k])
		{

		}
		free(tetrim[i]);
		i++;
	}
	free(tetrim);
}