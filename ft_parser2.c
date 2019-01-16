/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:22:10 by jebrocho          #+#    #+#             */
/*   Updated: 2019/01/14 16:11:20 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_stock(t_stock *stock, t_struct *stru)
{
	if ((stru->indic == 'd' || stru->indic == 'i' || stru->indic == 'o'
			|| stru->indic == 'u' || stru->indic == 'x' || stru->indic == 'X')
			&& stru->flag[7] == 0 && stru->flag[8] == 0)
		stock->stock_i = (int)va_arg(stru->ap, int);
	else if ((stru->indic == 'd' || stru->indic == 'i' || stru->indic == 'o'
				|| stru->indic == 'u' || stru->indic == 'x'
				|| stru->indic == 'X') && stru->flag[8] == 1)
		stock->stock_il = va_arg(stru->ap, long);
	else if ((stru->indic == 'd' || stru->indic == 'i' || stru->indic == 'o'
				|| stru->indic == 'u' || stru->indic == 'x'
				|| stru->indic == 'X') && stru->flag[7] == 1)
		stock->stock_ill = va_arg(stru->ap, long long);
	if (stru->indic == 'c')
		stock->stock_c = (char)va_arg(stru->ap, int);
	if (stru->indic == 's')
		stock->stock_s = va_arg(stru->ap, char*);
	if (stru->indic == 'f')
		stock->stock_f = va_arg(stru->ap, double);
}
