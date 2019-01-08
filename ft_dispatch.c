/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:36:39 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/08 12:07:00 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dispatch(t_struct *stru)
{
	if (stru->indic == 'c')
		ft_indic_c(stru);
	if (stru->indic == 's')
		;
	if (stru->indic == 'p')
		;
	if (stru->indic == 'd' || stru->indic == 'i')
		ft_indic_di(stru);
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
