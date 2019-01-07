/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indic_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:39:35 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/07 15:21:22 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_indic_c(t_struct *stru)
{
	int i;

	i = 1;
	if (stru->flag[0] == 1 || stru->flag[1] == 1 || stru->flag[3] == 1 ||
			stru->flag[4] == 1 || stru->prec > 0)
		exit(0); // or return or error or something
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
