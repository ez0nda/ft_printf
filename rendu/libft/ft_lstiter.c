/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:14:22 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/16 10:25:40 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *m;
	t_list *nxt;

	m = lst;
	while (m != NULL)
	{
		nxt = m->next;
		f(m);
		m = nxt;
	}
	lst = NULL;
}
