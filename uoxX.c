/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uoxX.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:02:21 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/07 17:03:17 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *u(int nb) //char * d'un unsigned int
{
	return(ft_itoa(ABS(nb)));
}

char *o(int nb) //char * d'un octal
{
	return(ft_itoa_base(nb, 8));
}

char *x(int nb) //char * d'un hexadecimal
{
	return(ft_itoa_base(nb, 16));
}

char	*X(int nb) //char * d'un hexadecimal avec maj
{
	return(ft_itoa_base_maj(nb, 16));
}