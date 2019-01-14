/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indic_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:10:01 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/11 11:24:37 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_indic_s(t_struct *stru, t_stock *stock)
{
	if (stru->flag[2] == 1)
		ft_putstr(stock->stock_s);
	if (stru->flag[0] == 1 && stru->flag[2] == 0)
	{
		while (stru->min_field > ft_strlen(stock->stock_s))
		{
			ft_putchar('0');
			stru->min_field--;
		}
	}
	while (stru->min_field > ft_strlen(stock->stock_s))
	{
		ft_putchar(' ');
		stru->min_field--;
	}
	if (stru->flag[2] == 0)
		ft_putstr(stock->stock_s);
}
