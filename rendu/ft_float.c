/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:29:10 by jebrocho          #+#    #+#             */
/*   Updated: 2019/01/24 06:00:59 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

double	ft_abs(double f)
{
	if (f < 0)
		return (-f);
	return (f);
}

void	ft_prec(t_struct * stru, long double f)
{
	int i;
	int nb;

	i = 0;
	while (i < stru->prec - 1)
	{
		f = f * 10;
		nb = f;
		ft_putnbr(nb, stru);
		f = f - nb;
		i++;
	}
	f = f * 100;
	nb = f;
	if (nb % 10 >= 5)
		nb = nb + 10;
	nb = nb / 10;
	ft_putnbr(nb, stru);
}

void	ft_print_dec(long double f, t_struct *stru)
{
	long	nb;
	int		i;

	i = 0;
	if (stru->prec > 0)
		ft_prec(stru, f);
	else
	{
		while (i < 6)
		{
			f *= 10;
//			printf("\n2:%Lf\n", f);
			nb = (int)f;
			f = f - nb;
//			printf("\n3:%Lf\n", f);
//			printf("\nnb : %d\n", nb);
			i++;
			if (i != 6)
				ft_putnbr(nb, stru);
		}
		if (nb % 10 >= 5)
			nb = nb + 10;
		nb = nb / 10;
		ft_putnbr(nb, stru);
	}
}

size_t	ft_fnbrsize(double f, t_struct *stru)
{
	size_t		i;
	int			j;

	if (f >= 0.000000)
		i = 1;
	else
		i = 2;
	j = f;
	i += ft_nbrsize(j);
	if (stru->flag[10] == 1 && stru->prec != 0)
		i += stru->prec;
	else if (stru->flag[10] == 1 && stru->prec == 0)
	{
		i--;
		return (i);
	}
	else if (stru->flag[10] == 0)
		i += 6;
	printf("\ni:%ld\n", i);
	return (i);
}

void	ft_print_float(long double f, t_struct *stru)
{
	long		nb_ent;
	size_t		pad2;

	pad2 = ft_fnbrsize(f, stru);
	if (f < 0)
		ft_putchar('-', stru);
	f = ft_abs(f);
	nb_ent = f;
	f = f - nb_ent;
	ft_putnbr(nb_ent, stru);
	ft_putchar('.', stru);
	ft_print_dec(f, stru);
}

void	ft_indic_f(t_struct *stru, t_stock *stock)
{
	ft_print_float(stock->stock_f, stru);
}
