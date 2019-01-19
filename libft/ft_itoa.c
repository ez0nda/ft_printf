/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:09:30 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/15 18:24:26 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strsize(int n)
{
	int		size;
	long	nb;

	size = 0;
	nb = n;
	if (nb == 0)
		size++;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb > 0)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

char			*ft_itoa(long n)
{
	int		i;
	long	nb;
	char	*str;

	i = 0;
	nb = n;
	if (!(str = ft_strnew(ft_strsize(n))))
		return (NULL);
	if (n < 0)
		nb = -nb;
	if (nb == 0)
		str[i++] = '0';
	while (nb > 0)
	{
		str[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
