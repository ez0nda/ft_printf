/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indic_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:39:35 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/17 16:01:22 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_indic_c(t_struct *stru, t_stock *stock)
{
	int i;

	i = 1;
	if (stru->flag[2] == 1)
		ft_putchar(stock->stock_c);
	if (stru->flag[0] == 1 && stru->flag[2] == 0)
	{
		while (stru->min_field > i)
		{
			ft_putchar('0');
			stru->min_field--;
		}
	}
	while (stru->min_field > i)
	{
		ft_putchar(' ');
		i++;
	}
	if (stru->flag[2] == 0)
		ft_putchar(stock->stock_c);
}

void	ft_indic_s(t_struct *stru, t_stock *stock)
{
	if (stru->flag[2] == 1 && stru->indic == 's')
		ft_putstr(stock->stock_s);
	if (stru->flag[0] == 1 && stru->flag[2] == 0)
	{
		while ((stru->min_field > ft_strlen(stock->stock_s)) &&
				(stru->indic == 's' || stru->prec == 0))
		{
			ft_putchar('0');
			stru->min_field--;
		}
	}
	while (stru->min_field > ft_strlen(stock->stock_s) && stru->indic == 's')
	{
		ft_putchar(' ');
		stru->min_field--;
	}
	if (stru->indic == 'x')
		ft_print_hexa(stru, stock);
	if (stru->flag[2] == 0)
		ft_putstr(stock->stock_s);
}

void	ft_indic_p(t_struct *stru, t_stock *stock)
{
	if (stru->flag[2] == 1)
		ft_putstr_free(ft_convert_hexa(stock->stock_i));
	if (stru->flag[0] == 1 && stru->flag[2] == 0)
	{
		while (stru->min_field > ft_nbrsize(stock->stock_i))
		{
			ft_putchar('0');
			stru->min_field--;
		}
	}
	while (stru->min_field > ft_nbrsize(stock->stock_i))
	{
		ft_putchar(' ');
		stru->min_field--;
	}
	if (stru->flag[2] == 0)
		ft_putstr_free(ft_convert_hexa(stock->stock_i));
}

void	ft_print_hexa(t_struct *stru, t_stock *stock)
{
	stru->stock_pre = stru->prec;
	stru->stock_pad = stru->min_field;
	if (stru->flag[2] == 0)
	{
		while (stru->min_field > ft_strlen(stock->stock_s)
				&& stru->min_field > stru->prec)
		{
			ft_putchar(' ');
			stru->min_field--;
		}
		while (stru->prec-- > ft_strlen(stock->stock_s))
			ft_putchar('0');
	}
	else
	{
		while (stru->prec-- > ft_strlen(stock->stock_s))
			ft_putchar('0');
		ft_putstr_free(ft_convert_hexa(stock->stock_i));
		if (stru->stock_pre != 0)
			while (stru->stock_pad-- > stru->stock_pre)
				ft_putchar(' ');
		else
			while (stru->stock_pad-- > ft_strlen(stock->stock_s))
				ft_putchar(' ');
	}
}
