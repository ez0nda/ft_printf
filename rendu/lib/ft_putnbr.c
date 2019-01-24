/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:25:08 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/24 03:46:56 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_l(uintmax_t nb, t_struct *stru)
{
	if (nb > 9)
	{
		ft_putnbr_l(nb / 10, stru);
		ft_putnbr_l(nb % 10, stru);
	}
	else
	{
		nb = nb + '0';
		ft_putchar(nb, stru);
	}
}

void	ft_putnbr(long n, t_struct *stru)
{
	long nb;

	nb = n;
	if (stru->modl == 0)
	{
		ft_putstr("-9223372036854775808", stru);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', stru);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, stru);
		ft_putnbr(nb % 10, stru);
	}
	else
	{
		nb = nb + '0';
		ft_putchar(nb, stru);
	}
}
