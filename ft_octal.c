/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:33:05 by jebrocho          #+#    #+#             */
/*   Updated: 2019/01/11 10:53:49 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void	ft_indic_o(t_struct *stru, t_stock *stock)
{
	int		oct;
	while (stock->stock_i != 0)
	{
		oct = stock->stock_i % 8 * 10;
		stock->stock_i /= 8;
	}
	oct = oct / 10;
}*/

char	*ft_indic_o(int octal_int)
{
	int		oct;
	int		count;
	char	*str;

	oct = 0;
	count = 0;
	while (octal_int != 0)
	{
		oct = (oct + octal_int % 8) * 10;
		octal_int /= 8;
		if (count != 0)
			count = count * 10;
		else
			count++;
	}
	oct = oct / 10;
	if (count > 10 && oct < 10)
	{
		oct = oct * count;
		str = ft_itoa(oct);
		return (str);
	}
	str = ft_itoa(oct);
	str = ft_strrev(str);
	return (str);
}
