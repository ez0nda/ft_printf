/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indic_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:39:35 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/12 16:39:31 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// creer un fichier apply_flag.c

void	ft_indic_c(t_struct *stru, t_stock *stock)
{
	stru->mod = 42;
	int i;

	i = 1;
	if (stru->flag[2] == 1)
		ft_putchar(stock->stock_c);
	while (stru->min_field > i)
	{
		ft_putchar(' ');
		i++;
	}
	if (stru->flag[2] == 0)
		ft_putchar(stock->stock_c);
}

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
		while (stru->stock_pad > stru->stock_pre++ && stru->flag[3] == 0)
			ft_putchar(' ');
	}
	if (stru->flag[3] == 1 && stru->flag[0] == 0 && stru->prec == 0)
		stru->min_field--;
	while (i < stru->min_field || i < stru->prec)
	{
		while (stru->prec > i && stru->flag[0] == 0)
		{
			ft_putchar('0');
			stru->prec--;
		}
		while (stru->min_field > i && stru->stock_pad > stru->stock_pre && stru->flag[0] == 0)
		{
			if (stru->prec == 0)
				ft_putchar(' ');
			stru->min_field--;
		}
		i++;;
	}
	if (stru->flag[2] == 1 && stru->prec != 0)
		ft_putnbr(stock->stock_i);
	if (stru->flag[2] == 0)
	{
		if (stru->flag[3] == 1 && stru->flag[0] == 0 && stru->prec == 0)
		{
//			if (stock->stock_i >= 0)//ft_putchar('+');
//			{
				ft_putchar(stock->stock_i >= 0 ? '+' : 'X');
//				printf("\nim here 1\n");
//			}
		}
		ft_putnbr(stock->stock_i);
	}
	if (stru->prec > 0 && stru->flag[2] == 1)
	{
		if (stru->flag[3] == 1)
			stru->stock_pad--;
		while (stru->stock_pad > stru->stock_pre++)
			ft_putchar(' ');
	}
}

void	ft_apply_flags(t_struct *stru, t_stock *stock)
{
	int i;
	int nik = 0;
	i = stru->min_field - ft_nbrsize(stock->stock_i);
	if (stru->flag[2] == 1 && stru->flag[0] == 1)
		stru->flag[0] = 0;
	if (stru->flag[0] == 1 && stru->prec > 0)
		stru->flag[0] = 0;
	while (stru->flag[3] == 1 && ++nik < stru->min_field - stru->prec && stru->prec != 0 && stru->flag[2] == 0)
		ft_putchar(' ');
	if (stru->flag[3] == 1 && (stru->prec != 0 || stru->flag[0] == 1))
	{
	//	if (stock->stock_i >= 0)
	//	{
			ft_putchar(stock->stock_i >= 0 ? '+' : 'X');
	//		printf("\nim here 2\n");
	//	}
		i--;
	}
	if (stru->flag[2] == 1 && stru->prec == 0)
	{
		ft_putnbr(stock->stock_i);
		if (stru->flag[0] == 1)
			stru->flag[0] = 0;
	}
	if (stru->flag[4] == 1 && (stru->min_field < stru->prec || stru->flag[0] == 1))
	{
		ft_putchar(' ');
		i--;
	}
	while (stru->flag[0] == 1 && i > 0)
	{
		ft_putchar('0');
		i--;
	}
}

int		ft_nbrsize(int nb)
{
	int		size;

	size = 0;
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	if (nb == 0)
		size++;
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}