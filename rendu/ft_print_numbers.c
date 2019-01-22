/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:39:35 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/19 18:23:32 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_indic_di(t_struct *stru, t_stock *stock)
{
	int i;

	if (stru->flag[7] == 0 && stru->flag[8] == 0 && (stru->indic == 'i'
				|| stru->indic == 'd'))
		stock->stock_il = (int)stock->stock_i;
	i = ft_nbrsize(stock->stock_il);
	stru->stock_pad = stru->min_field;
	stru->stock_pre = stru->prec;
	ft_apply_flags(stru, stock);
	if (stru->flag[4] == 1 && stru->flag[3] == 0 && stru->prec == 0
			&& stru->min_field == 0 && stock->stock_il >= 0)
		ft_putchar(' ', stru);
	if (stru->prec > 0 && stru->flag[2] == 0)
	{
		if (stru->flag[3] == 1 && (stru->prec != 0 || stru->flag[0] == 1))
			stru->stock_pad--;
		while (stru->stock_pad > stru->stock_pre++ && stock->stock_il >= 0
				&& stru->flag[3] == 0)
			ft_putchar(' ', stru);
	}
	if (stru->flag[3] == 1 && stru->flag[0] == 0 && stru->prec == 0)
		stru->min_field--;
	if (stock->stock_il < 0 && stru->stock_pad > stru->stock_pre
			&& stru->prec > 0)
		stru->prec++;
	ft_apply_flags3(stru, stock, i);
}

void	ft_apply_flags3(t_struct *stru, t_stock *stock, int i)
{
	while (i < stru->min_field || i < stru->prec)
	{
		while (stru->prec > i && stock->stock_il >= 0)
		{
			ft_putchar('0', stru);
			stru->prec--;
		}
		while (stru->prec > i && stock->stock_il < 0)
		{
			ft_putchar('0', stru);
			stru->prec--;
		}
		if (stru->stock_pre > stru->min_field && stock->stock_il < 0)
			ft_putchar('0', stru);
		while (stru->min_field > i && stru->min_field > stru->stock_pre
				&& stru->flag[0] == 0)
		{
			if (stru->prec == 0)
				ft_putchar(' ', stru);
			stru->min_field--;
		}
		if (stru->stock_pad > i && stru->stock_pad > stru->stock_pre && stock->stock_il == 0)
			ft_putchar(' ', stru);
		if (stock->stock_il < 0 && stru->flag[3] == 1 && stru->prec == 0
				&& stru->flag[0] == 0)
		{
			ft_putchar(' ', stru);
		}
		i++;
	}
	if (stru->flag[3] == 1 && stru->prec > stru->min_field && stru->prec != 0
			&& stru->min_field != 0)
		ft_putchar('0', stru);
	ft_apply_flags4(stru, stock);
}

void	ft_apply_flags4(t_struct *stru, t_stock *stock)
{
	if (stock->stock_il < 0 && stru->flag[3] == 1 && stru->prec == 0
			&& stru->flag[0] == 1)
		ft_putchar('0', stru);
	if (stru->flag[2] == 1 && stru->prec != 0)
		ft_putnbr(stock->stock_il >= 0 ? stock->stock_il : stock->stock_il * -1, stru);
	if (stru->flag[2] == 0 && ((stru->flag[10] == 1 && (stru->prec != 0 || stock->stock_il != 0)) || (stru->flag[10] == 0)))
	{
		if (stru->flag[3] == 1 && stock->stock_il >= 0 && stru->flag[0] == 0
				&& stru->prec == 0)
			ft_putchar('+', stru);
		if (stru->prec != 0 || stru->flag[0] == 1)
			ft_putnbr(stock->stock_il >= 0 ?
					stock->stock_il : stock->stock_il * -1, stru);
		else
			ft_putnbr(stock->stock_il, stru);
	}
	else if (stru->flag[2] == 0 && stru->flag[10] == 1 && (stru->prec != 0 || stock->stock_il != 0) && stru->stock_pad > 0)
		ft_putchar(' ', stru);
	if (stru->prec > 0 && stru->flag[2] == 1)
	{
		if (stru->flag[3] == 1 || stock->stock_il < 0)
			stru->stock_pad--;
		while (stru->stock_pad > stru->stock_pre++)
			ft_putchar(' ', stru);
	}
}

void	ft_apply_flags(t_struct *stru, t_stock *stock)
{
	int i;
	int j;

	j = 0;
	i = stru->min_field - ft_nbrsize(stock->stock_il);
	if ((stru->flag[2] == 1 && stru->flag[0] == 1) ||
			(stru->flag[0] == 1 && stru->prec > 0))
		stru->flag[0] = 0;
	while (stru->flag[3] == 1 && ++j < stru->min_field - stru->prec
			&& stru->prec != 0 && stru->flag[2] == 0)
		ft_putchar(' ', stru);
	while (++j < stru->min_field - stru->prec && stru->prec != 0
			&& stru->flag[2] == 0 && stock->stock_il < 0)
		ft_putchar(' ', stru);
	if (stock->stock_il < 0 && (stru->flag[0] == 1 || stru->prec > 0
				|| stru->flag[2] == 1))
		ft_putchar('-', stru);
	if (stru->flag[3] == 1 && (stru->prec != 0 || stru->flag[0] == 1
				|| stru->flag[2] == 1))
	{
		if (stock->stock_il >= 0)
			ft_putchar('+', stru);
		i--;
	}
	ft_apply_flags2(stru, stock, i);
}

void	ft_apply_flags2(t_struct *stru, t_stock *stock, int i)
{
	if (stru->flag[2] == 1 && stru->prec == 0)
	{
		if (stru->flag[10] == 1 && stru->prec == 0 && stock->stock_il == 0)
			ft_putchar(' ', stru);
		else
			ft_putnbr(stock->stock_il >= 0 ? stock->stock_il : stock->stock_il * -1, stru);
		if (stru->flag[0] == 1)
			stru->flag[0] = 0;
	}
	if (stru->flag[4] == 1 && (stru->min_field < stru->prec
				|| stru->flag[0] == 1))
	{
		ft_putchar(' ', stru);
		i--;
	}
//	if (stock->stock_il < 0 && stru->prec != 0 && stru->prec > stru->min_field)
//		ft_putchar('5', stru);
	while (stru->flag[0] == 1 && i > 0)
	{
		ft_putchar('0', stru);
		i--;
	}
}
