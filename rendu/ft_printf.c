/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 09:05:54 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/24 07:09:42 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_struct	stru;
	t_stock		stock;
	int			i;

	va_start(stru.ap, format);
	i = 0;
	stru.count_char = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_find_indicator(&format[i], &stru);
			ft_check_width(&format[i], &stru);
			ft_check_precision(&format[i], &stru);
			ft_check_flags(&format[i], &stru, &stock);
			while (format[i] != stru.indic)
				i++;
		}
		else if (format[i] != '%')
			ft_putchar(format[i], &stru);
		i++;
	}
	va_end(stru.ap);
	return (stru.count_char);
}
