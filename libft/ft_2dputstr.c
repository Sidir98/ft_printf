/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dputstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:05:39 by ibouabda          #+#    #+#             */
/*   Updated: 2019/04/02 11:54:31 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2dputstr(char **tetrim)
{
	size_t i;

	i = 0;
	while (tetrim[i])
	{
		ft_putendl(tetrim[i]);
		i++;
	}
}
