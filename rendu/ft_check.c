/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:08:37 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/09 11:33:28 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_indic_c(const char *format, t_struct *stru)
{
	int i;
	int j;

	i = 0;
	j = 3;
	while (format[i] != stru->indic)
	{
		if (format[i] == '.' || stru->flag[0] == 1 || stru->flag[1] == 1)
			return (0);
		while (j <= 9)
			if (stru->flag[j++] == 1)
				return (0);
		i++;
	}
	return (1);
}

int		ft_check_indic_di(const char *format, t_struct *stru)
{
	(void)format;
	stru->mod = 42;
	return (0);
}
