/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3Dputstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:30:16 by ibouabda          #+#    #+#             */
/*   Updated: 2019/03/18 16:40:25 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_3dputstr(char ***tetrim)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	while (tetrim[i])
	{
		while (tetrim[i][k])
		{
			ft_putendl(tetrim[i][k]);
			k++;
		}
		ft_putchar('\n');
		k = 0;
		i++;
	}
}
