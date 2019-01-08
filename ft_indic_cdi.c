/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indic_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:39:35 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/08 15:38:52 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// creer un fichier apply_flag.c

void	ft_indic_c(t_struct *stru)
{
	int i;

	i = 1;
	if (stru->flag[0] == 1 || stru->flag[1] == 1 || stru->flag[3] == 1 ||
			stru->flag[4] == 1 || stru->prec > 0)
		exit(0); // or return or error_msg or something
	if (stru->flag[2] == 1)
		ft_putchar((char)va_arg(stru->ap, int));
	while (stru->min_field > i)
	{
		ft_putchar(' ');
		i++;
	}
	if (stru->flag[2] == 0)
		ft_putchar((char)va_arg(stru->ap, int));
}

void	ft_indic_di(t_struct *stru)
{
	int i;

	i = 1;
//	i = ft_nbrsize(va_arg(stru->ap, int));
//	printf("size = %d\n", i);
	if (stru->flag[1] == 1 || (stru->flag[0] == 1 && stru->flag[2] == 1))
		exit(0);
	if (stru->flag[2] == 1)
		ft_putnbr(va_arg(stru->ap, int));
	if (stru->flag[4] == 1)
		ft_putchar(' ');
	if (stru->flag[3] == 1/* && va_arg(stru->ap, int)*/) // && arg > 0
		ft_putchar('+');
	while (stru->min_field > i && stru->min_field > stru->prec)
	{
		if (stru->flag[0] == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
//		i++;
		stru->min_field--;
	}
	while (stru->prec > i)
	{
		ft_putchar('0');
		i++;
	}
	if (stru->flag[2] == 0)
		ft_putnbr(va_arg(stru->ap, int));
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
