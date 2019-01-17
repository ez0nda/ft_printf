/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:39:35 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/17 11:23:08 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_indic_di(t_struct *stru, t_stock *stock)
{
	int i;

	i = ft_nbrsize(stock->stock_i);
	stru->stock_pad = stru->min_field;
	stru->stock_pre = stru->prec;
	ft_apply_flags(stru, stock);
	if (stru->prec > 0 && stru->flag[2] == 0)
	{
		if (stru->flag[3] == 1 && (stru->prec != 0 || stru->flag[0] == 1))
			stru->stock_pad--;
		while (stru->stock_pad > stru->stock_pre++ && stock->stock_i >= 0
				&& stru->flag[3] == 0)
			ft_putchar(' ');
	}
	if (stru->flag[3] == 1 && stru->flag[0] == 0 && stru->prec == 0)
		stru->min_field--;
	if (stock->stock_i < 0 && stru->stock_pad > stru->stock_pre
			&& stru->prec > 0)
		stru->prec++;
	ft_apply_flags3(stru, stock, i);
}

void	ft_apply_flags3(t_struct *stru, t_stock *stock, int i)
{
	while (i < stru->min_field || i < stru->prec)
	{
		while (stru->prec > i && stru->flag[0] == 0)
		{
			ft_putchar('0');
			stru->prec--;
		}
		while (stru->min_field > i && stru->stock_pad > stru->stock_pre
				&& stru->flag[0] == 0)
		{
			if (stru->prec == 0)
				ft_putchar(' ');
			stru->min_field--;
		}
		if (stock->stock_i < 0 && stru->flag[3] == 1 && stru->prec == 0
				&& stru->flag[0] == 0)
		{
			ft_putchar(' ');
		}
		i++;
	}
	if (stru->flag[3] == 1 && stru->prec > stru->min_field && stru->prec != 0
			&& stru->min_field != 0)
		ft_putchar('0');
	ft_apply_flags4(stru, stock);
}

void	ft_apply_flags4(t_struct *stru, t_stock *stock)
{
	if (stock->stock_i < 0 && stru->flag[3] == 1 && stru->prec == 0
			&& stru->flag[0] == 1)
		ft_putchar('0');
	if (stru->flag[2] == 1 && stru->prec != 0)
		ft_putnbr(stock->stock_i >= 0 ? stock->stock_i : stock->stock_i * -1);
	if (stru->flag[2] == 0)
	{
		if (stru->flag[3] == 1 && stock->stock_i >= 0 && stru->flag[0] == 0
				&& stru->prec == 0)
			ft_putchar('+');
		if (stru->prec != 0 || stru->flag[0] == 1)
			ft_putnbr(stock->stock_i >= 0 ?
					stock->stock_i : stock->stock_i * -1);
		else
			ft_putnbr(stock->stock_i);
	}
	if (stru->prec > 0 && stru->flag[2] == 1)
	{
		if (stru->flag[3] == 1 || stock->stock_i < 0)
			stru->stock_pad--;
		while (stru->stock_pad > stru->stock_pre++)
			ft_putchar(' ');
	}
}

void	ft_apply_flags(t_struct *stru, t_stock *stock)
{
	int i;
	int j;

	j = 0;
	i = stru->min_field - ft_nbrsize(stock->stock_i);
	if ((stru->flag[2] == 1 && stru->flag[0] == 1) ||
			(stru->flag[0] == 1 && stru->prec > 0))
		stru->flag[0] = 0;
	while (stru->flag[3] == 1 && ++j < stru->min_field - stru->prec
			&& stru->prec != 0 && stru->flag[2] == 0)
		ft_putchar(' ');
	while (++j < stru->min_field - stru->prec && stru->prec != 0
			&& stru->flag[2] == 0 && stock->stock_i < 0)
		ft_putchar(' ');
	if (stock->stock_i < 0 && (stru->flag[0] == 1 || stru->prec > 0
				|| stru->flag[2] == 1))
		ft_putchar('-');
	if (stru->flag[3] == 1 && (stru->prec != 0 || stru->flag[0] == 1
				|| stru->flag[2] == 1))
	{
		if (stock->stock_i >= 0)
			ft_putchar('+');
		i--;
	}
	ft_apply_flags2(stru, stock, i);
}

void	ft_apply_flags2(t_struct *stru, t_stock *stock, int i)
{
	if (stru->flag[2] == 1 && stru->prec == 0)
	{
		ft_putnbr(stock->stock_i >= 0 ? stock->stock_i : stock->stock_i * -1);
		if (stru->flag[0] == 1)
			stru->flag[0] = 0;
	}
	if (stru->flag[4] == 1 && (stru->min_field < stru->prec
				|| stru->flag[0] == 1))
	{
		ft_putchar(' ');
		i--;
	}
	if (stock->stock_i < 0 && stru->prec != 0 && stru->prec > stru->min_field)
		ft_putchar('0');
	while (stru->flag[0] == 1 && i > 0)
	{
		ft_putchar('0');
		i--;
	}
}
