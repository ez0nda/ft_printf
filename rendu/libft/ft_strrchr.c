/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 00:50:36 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/14 11:20:53 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*t;

	t = NULL;
	while (*s)
	{
		if (*s == (char)c)
			t = (char*)s;
		s++;
	}
	if (*s == (char)c)
		return ((char*)s);
	else
		return (t);
}
