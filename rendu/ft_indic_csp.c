/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indic_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:39:35 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/16 15:24:47 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_indic_c(t_struct *stru, t_stock *stock)
{
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
