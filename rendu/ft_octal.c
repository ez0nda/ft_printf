/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:33:05 by jebrocho          #+#    #+#             */
/*   Updated: 2019/01/11 14:58:39 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_form_o(long long oct, long long count, char *str)
{
	if (count >= 10 && oct < 10)
	{
		oct = oct * count;
		str = ft_itoa(oct);
		return (str);
	}
	if (ft_nbrsize(count) > ft_nbrsize(oct))
	{
		str = ft_itoa(oct);
		str = ft_strrev(str);
		oct = ft_atoi(str);
		oct = oct * ft_recursive_power(10, ft_nbrsize(count) - ft_nbrsize(oct));
		str = ft_itoa(oct);
		return (str);
	}
	return (NULL);
}

char	*ft_convert_o(long long octal_int)
{
	long long		oct;
	long long		count;
	char	*str;

	oct = 0;
	count = 0;
	while (octal_int != 0)
	{
		oct = (oct + octal_int % 8) * 10;
		octal_int /= 8;
		if (count != 0)
			count = count * 10;
		else
			count++;
	}
	oct = oct / 10;
	if ((str = ft_form_o(oct, count, str)) != NULL)
		return (str);
	str = ft_itoa(oct);
	str = ft_strrev(str);
	return (str);
}


void		ft_indic_o(t_struct *stru, t_stock *stock)
{
	if (stru->flag[7] == 1)
	{
		ft_putstr(ft_convert_o(stock->stock_ill));
		return ;
	}
	if (stru->flag[8] == 1)
	{
		ft_putstr(ft_convert_o(stock->stock_il));
		return ;
	}
	ft_putstr(ft_convert_o(stock->stock_i));
}
