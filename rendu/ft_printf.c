/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 09:05:54 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/16 15:24:20 by ezonda           ###   ########.fr       */
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
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_find_indicator(&format[i], &stru, &stock);
			ft_check_width(&format[i], &stru);
			ft_check_precision(&format[i], &stru);
			ft_check_flags(&format[i], &stru, &stock);
			while (format[i] != stru.indic)
				i++;
		}
		else if (format[i] != '%') // if format valid
			write(1, &format[i], 1);
		i++;
	}
	va_end(stru.ap);
	return (0);
}

int		main(void)
{
	int ptr;
//	ft_printf(" %15c %c %c %c", 48, 55, 56, 57);
//	printf("\nprintf\n %15c %c %c %c", 48, 55, 56, 57);
//	ft_printf("%10.9d %5d %.3d %d", 1, 2, 3, 4);
//	printf("\nprintf\n%10.9d %5d %.3d %d", 1, 2, 3, 4);
//	ft_printf("%+-15.20i", -42);
//	printf("\nprintf \n%+-15.20i", -42);
//	ft_printf(" %010s %s", "hello", "world");
//	printf("\npf\n %010s %s", "hello", "world");
//	ft_printf("%-+35.20d", 42);
//	printf("\nprintf \n%-+35.20d", 42);
	ft_printf("%x", &ptr);
	printf("\nprintf \n%p", &ptr);
//	printf("\nprintf \n%x", &ptr);
//	printf("\nprintf \n%lx", &ptr);
	return (0);
}
