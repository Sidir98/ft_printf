/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:13:35 by ibouabda          #+#    #+#             */
/*   Updated: 2018/11/28 14:34:18 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *m;
	t_list *erase;

	m = *alst;
	while (m != NULL)
	{
		erase = m;
		m = m->next;
		del(erase->content, erase->content_size);
		free(erase);
	}
	*alst = NULL;
}
