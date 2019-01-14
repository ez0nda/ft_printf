/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:36:39 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/14 16:07:30 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		ft_indic_o(stru, stock);
	if (stru->indic == 'u')
		;
	if (stru->indic == 'x' || stru->indic == 'X')
		ft_indic_h(stru, stock);
	if (stru->indic == 'f')
		ft_indic_f(stru, stock);
	ft_initialize_flags(stru);
}
