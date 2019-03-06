/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indic_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:12:44 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/25 21:54:33 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_putstr_free(char *s, t_struct *stru)
{
	long i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], stru);
		i++;
	}
	free(s);
}

long	ft_abs(long nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	ft_indic_mod(t_struct *stru)
{
	int i;

	i = 1;
	if (stru->flag[2] == 1)
		ft_putchar('%', stru);
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
		ft_putchar('%', stru);
}
