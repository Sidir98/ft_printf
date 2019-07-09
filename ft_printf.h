/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:12:29 by ibouabda          #+#    #+#             */
/*   Updated: 2019/07/09 16:27:08 by ibouabda         ###   ########.fr       */
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

char	*u(int nb);
char	*o(int nb);
char	*x(int nb);
char	*X(int nb);
char	*s(char *str);
char	*c(int c);
char	*p(void *ptr);
int		arrondi(double nb, int b);
char	*f(double nb, int precs);

# include "libft/libft.h"
# include <stdarg.h>
# include "stdio.h"
#endif
