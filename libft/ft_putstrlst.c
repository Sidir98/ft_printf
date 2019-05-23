/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:19:20 by ibouabda          #+#    #+#             */
/*   Updated: 2018/11/28 13:26:45 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrlst(t_list *lst)
{
	t_list *m;

	m = lst;
	while (m)
	{
		ft_putstr((char *)m->content);
		ft_putchar('\n');
		m = m->next;
	}
}
