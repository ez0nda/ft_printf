/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 22:27:14 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/12 09:01:54 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*s1;
	const char	*s2;

	i = 0;
	s1 = (char *)dst;
	s2 = (const char *)src;
	while (n--)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
