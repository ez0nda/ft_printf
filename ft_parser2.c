/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:22:10 by jebrocho          #+#    #+#             */
/*   Updated: 2019/01/11 10:53:44 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_stock(t_stock *stock, t_struct *stru)
{
	if (stru->indic == 'd' || stru->indic == 'i' || stru->indic == 'o'
			|| stru->indic == 'u' || stru->indic == 'x' || stru->indic == 'X')
		stock->stock_i = va_arg(stru->ap, int);
	if (stru->indic == 'c')
		stock->stock_c = (char)va_arg(stru->ap, int);
	if (stru->indic == 's')
		stock->stock_s = va_arg(stru->ap, char*);
	if (stru->indic == 'f')
		stock->stock_f = (float)va_arg(stru->ap, int);
}
