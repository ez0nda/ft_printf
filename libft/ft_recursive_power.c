/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:26:27 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/15 18:17:15 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_recursive_power(long nb, long pow)
{
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	else
		return (nb * (ft_recursive_power(nb, --pow)));
}
