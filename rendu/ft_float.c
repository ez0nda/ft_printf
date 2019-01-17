/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:29:10 by jebrocho          #+#    #+#             */
/*   Updated: 2019/01/17 10:25:12 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_prec(t_struct * stru, long double f)
{
	int i;
	int nb;

	i = 0;
	while (i < stru->prec - 1)
	{
		f = f * 10;
		nb = f;
		ft_putnbr(nb);
		f = f - nb;
		i++;
	}
	f = f * 100;
	nb = f;
	if (nb % 10 >= 5)
		nb = nb + 10;
	nb = nb / 10;
	ft_putnbr(nb);
}

void	ft_print_dec(long double f, t_struct *stru)
{
	int		i;
	int		nb;

	i = 0;
	if (stru->prec > 0)
		ft_prec(stru, f);
	else
	{
		f = f * 10000000;
		nb = f;
		if (nb % 10 >= 5)
			nb = nb + 10;
		nb = nb / 10;
		ft_putnbr(nb);
	}
}

void	ft_print_float(long double f, t_struct *stru)
{
//	long		nb_dec;
	long		nb_ent;

	nb_ent = f;
	f = f - nb_ent;
	ft_putnbr(nb_ent);
	ft_putchar('.');
	ft_print_dec(f, stru);
}

void	ft_indic_f(t_struct *stru, t_stock *stock)
{
	ft_print_float(stock->stock_f, stru);
}
