/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indic_csp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:39:35 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/19 18:06:44 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_indic_c(t_struct *stru, t_stock *stock)
{
	int i;

	i = 1;
	if (stru->flag[2] == 1)
		ft_putchar(stock->stock_c, stru);
	if (stru->flag[0] == 1 && stru->flag[2] == 0)
	{
		while (stru->min_field > i)
		{
			ft_putchar('0', stru);
			stru->min_field--;
		}
	}
	while (stru->min_field > i)
	{
		ft_putchar(' ', stru);
		i++;
	}
	if (stru->flag[2] == 0)
		ft_putchar(stock->stock_c, stru);
}

void	ft_indic_s(t_struct *stru, t_stock *stock)
{
	if (stru->indic == 's' && stru->prec < ft_strlen(stock->stock_s))
		stock->stock_s = ft_strsub(stock->stock_s, 0, stru->prec);
	if (stru->flag[2] == 1 && stru->indic == 's')
		ft_putstr(stock->stock_s, stru);
	if (stru->flag[0] == 1 && stru->flag[2] == 0)
	{
		while ((stru->min_field > ft_strlen(stock->stock_s)) &&
				(stru->indic == 's' || stru->prec == 0))
		{
			ft_putchar('0', stru);
			stru->min_field--;
		}
	}
	while (stru->min_field > ft_strlen(stock->stock_s) && stru->indic == 's')
	{
		ft_putchar(' ', stru);
		stru->min_field--;
	}
	if (stru->indic == 'x')
		ft_print_hexa(stru, stock);
	if (stru->flag[2] == 0)
		ft_putstr(stock->stock_s, stru);
}

void	ft_indic_p(t_struct *stru, t_stock *stock)
{
	if (stru->flag[2] == 1)
	{
		ft_putstr("0x", stru);
		ft_putstr_free(ft_convert_hexa(stock->stock_ill), stru);
	}
	if (stru->flag[0] == 1 && stru->flag[2] == 0)
	{
		while (stru->min_field > ft_nbrsize(stock->stock_ill))
		{
			ft_putchar('0', stru);
			stru->min_field--;
		}
	}
	while (stru->min_field > ft_nbrsize(stock->stock_ill))
	{
		ft_putchar(' ', stru);
		stru->min_field--;
	}
	if (stru->flag[2] == 0)
	{
		ft_putstr("0x", stru);
		ft_putstr_free(ft_convert_hexa(stock->stock_ill), stru);
	}
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
			ft_putchar(' ', stru);
			stru->min_field--;
		}
		while (stru->prec-- > ft_strlen(stock->stock_s))
			ft_putchar('0', stru);
	}
	else
	{
		while (stru->prec-- > ft_strlen(stock->stock_s))
			ft_putchar('0', stru);
		ft_putstr_free(ft_convert_hexa(stock->stock_il), stru);
		if (stru->stock_pre != 0)
			while (stru->stock_pad-- > stru->stock_pre)
				ft_putchar(' ', stru);
		else
			while (stru->stock_pad-- > ft_strlen(stock->stock_s))
				ft_putchar(' ', stru);
	}
}
