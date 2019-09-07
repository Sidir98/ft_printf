/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:12:29 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/07 17:04:42 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H
# define ABS(Value) (Value < 0 ? Value * -1 : Value)
# include "libft/libft.h"
# include <stdarg.h>
# include "stdio.h"

typedef int (*fptr)(int);

typedef	struct		s_f
{
	fptr			ft;
}					t_f;

char	*u(int nb);
char	*o(int nb);
char	*x(int nb);
char	*X(int nb);
char	*c(int c);
char	*p(void *ptr);
int		arrondi(double nb, int b);
char	*f(double nb, int precs);

#endif
