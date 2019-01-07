/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 09:05:54 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/07 15:28:03 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_struct	stru;
	int			i;

	va_start(stru.ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			stru.mod = 1;
			ft_find_indicator(&format[i], &stru);
			ft_check_width(&format[i], &stru);
			ft_check_precision(&format[i], &stru);
			// ft_flag_error (in dispatch.c) ?
			ft_check_flags(&format[i], &stru);
			while (format[i] != stru.indic)
				i++;
		}
		else if (format[i] != '%' && stru.mod != 1)
			write(1, &format[i], 1);
		i++;
	}
	va_end(stru.ap);
	return (0);
}

int		main(void)
{
//	ft_printf("%12c %4c %6c %1c", 'Z', 'A', 48, 49);
//	printf("%12c %4c %6c %1c", 'Z', 'A', 48, 49);
	ft_printf("%14c", 55);
//	printf("%12c", 55);
	return (0);
}
