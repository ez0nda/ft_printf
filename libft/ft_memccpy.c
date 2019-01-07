/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:09:22 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/14 13:01:05 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char*)src;
	s2 = (char*)dst;
	while (n > 0 && *s1 != (char)c)
	{
		n--;
		*s2++ = *s1++;
	}
	if (n > 0)
	{
		*s2++ = *s1++;
		return ((void*)s2);
	}
	else
		return (NULL);
}
