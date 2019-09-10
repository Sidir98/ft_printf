/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:12:29 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/09 13:31:28 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include "stdio.h" //a supprimer

typedef int (*fptr)(int);

typedef	struct		s_f
{
	fptr			ft;
}					t_f;

typedef	struct		spf_spe
{
	char			flag;
	int				nbl;
	int				nbp;
	int				precs;
	char			*convert;
	char			arg;
}					pf_spe;

char	*u(int nb);
char	*o(int nb);
char	*x(int nb);
char	*X(int nb);
char	*c(int c);
char	*p(void *ptr);
int		arrondi(double nb, int b);
char	*f(double nb, int precs);
int		ft_prstr2chr(char *src, char *to_find);

#endif
