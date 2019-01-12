/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:36:39 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/11 11:20:04 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*void	ft_check_format(const char *format, t_struct *stru)
{
	if (stru->indic == 'c')
		stru->valid = ft_check_indic_c(format, stru);
	if (stru->indic == 's')
		str;
	if (stru->indic == 'p')
		;
	if (stru->indic == 'd' || stru->indic == 'i')
		stru->valid = ft_check_indic_di(format, stru);
	if (stru->indic == 'o')
		;
	if (stru->indic == 'u')
		;
	if (stru->indic == 'x')
		;
	if (stru->indic == 'X')
		;
	if (stru->indic == 'f')
		;
}*/

void	ft_dispatch(t_struct *stru, t_stock *stock)
{
	if (stru->indic == 'c')
		ft_indic_c(stru, stock);
	if (stru->indic == 's')
		ft_indic_s(stru, stock);
	if (stru->indic == 'p')
		;
	if (stru->indic == 'd' || stru->indic == 'i')
		ft_indic_di(stru, stock);
	if (stru->indic == 'o')
		;
	if (stru->indic == 'u')
		;
	if (stru->indic == 'x')
		;
	if (stru->indic == 'X')
		;
	if (stru->indic == 'f')
		;
}
