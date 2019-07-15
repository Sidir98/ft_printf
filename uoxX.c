/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uoxX.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:02:21 by ibouabda          #+#    #+#             */
/*   Updated: 2019/07/15 16:51:13 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *u(int nb)
{
	return(ft_itoa(ABS(nb)));
}

char *o(int nb)
{
	return(ft_itoa_base(nb, 8));
}

char *x(int nb)
{
	return(ft_itoa_base(nb, 16));
}

char	*X(int nb)
{
	return(ft_itoa_base_maj(nb, 16));
}