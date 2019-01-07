/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:26:27 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/16 13:28:18 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_recursive_power(int nb, int pow)
{
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	else
		return (nb * (ft_recursive_power(nb, --pow)));
}
