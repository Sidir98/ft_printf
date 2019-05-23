/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:12:29 by ibouabda          #+#    #+#             */
/*   Updated: 2019/05/22 17:31:02 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H
# define ABS(Value) (Value < 0 ? Value * -1 : Value)

typedef int (*fptr)(int);

typedef	struct		s_f
{
	fptr			ft;
}					t_f;

# include "libft/libft.h"
# include <stdarg.h>
# include "stdio.h"
#endif
