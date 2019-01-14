/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:07:05 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/16 10:24:45 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *m;
	t_list *nxt;

	m = *alst;
	while (m != NULL)
	{
		nxt = m->next;
		del(m->content, m->content_size);
		free(m);
		m = nxt;
	}
	*alst = NULL;
}
