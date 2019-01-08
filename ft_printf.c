/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 09:05:54 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/08 16:55:58 by ezonda           ###   ########.fr       */
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
			// ft_flag_error (in dispatch.c / find_indicator) ?
			ft_check_flags(&format[i], &stru);
			while (format[i] != stru.indic)
				i++;
		}
		else if (format[i] != '%' && stru.mod != 1) // if format valid
			write(1, &format[i], 1);
		i++;
	}
	va_end(stru.ap);
	return (0);
}

int		main(void)
{
//	ft_printf("hello %12 c %4c world %6c %1c test", 'Z', 'A', 48, 49);
//	printf("\nprintf\nhello %12 c %4c world %6c %1c test", 'Z', 'A', 48, 49);
	ft_printf("%-14c", 55);
	printf("\nprintf\n%-14c", 55);
//	ft_printf("%10.9d %5d %.3d %d", 1, 2, 3, 4);
//	printf("\nprintf\n%10.9d %5d %.3d %d", 1, 2, 3, 4);
//	ft_printf("%05d", 12);
//	printf("\npf\n%05d", 12);
	return (0);
}
