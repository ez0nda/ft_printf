/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:49:28 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/16 15:52:00 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_prime(int nb)
{
	long i;

	i = 0;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while (i * i < nb)
		i++;
	while ((nb % i != 0) && (i > 2))
		i--;
	return (nb % i);
}