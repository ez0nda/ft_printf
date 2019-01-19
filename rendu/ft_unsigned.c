/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:55:40 by jebrocho          #+#    #+#             */
/*   Updated: 2019/01/19 17:23:51 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

long		ft_abs(long i)
{
	if (i < 0)
		return (-i);
	return (i);
}

char		*ft_minus_char(char *str, long i)
{
	int l;
	int v;

	l = 20;
	while (i != 0)
	{
		if ((str[--l] - i % 10) >= '0')
			str[l] = str[l] - i % 10;
		else
		{
			if (l - 1 == 8 || l - 1 == 14)
			{
				str[l - 2]--;
				v = i % 10 - (str[l] - '0') - 1;
			}
			else
			{
				str[l - 1]--;
				v = i % 10 - (str[l] - '0') - 1;
			}
			str[l] = '9' - v;
		}
		i /= 10;
	}
	return (str);
}

char		*ft_case_lu_signed(t_stock *stock)
{
	char	*str;
	long	i;

	if (!(str = ft_strdup("18446744071562067968")))
		return (NULL);
	i = ft_abs(stock->stock_il + 2147483648);
	str = ft_minus_char(str, i);
	return (str);
}

long long	ft_find_u(t_stock *stock, int i)
{
	if (i == 0)
	{
		if (stock->stock_il < 0 && stock->stock_il % 4294967296 != 0)
			return (4294967296 + stock->stock_il % 4294967296);
		else if (stock->stock_il % 4294967296 == 0)
			return (0);
		if (stock->stock_il > 4294967295)
			return (stock->stock_il - 4294967296);
		else
			return (stock->stock_il);
	}
	else
	{
		if (stock->stock_il < 0 && stock->stock_il > -2147483648)
			return (4294967296 + stock->stock_il);
		else if (stock->stock_il <= -2147483648)
			return (-1);
		return (stock->stock_il);
	}
}

void	ft_indic_u(t_struct *stru, t_stock *stock)
{
	if (stru->flag[7] == 0 && stru->flag[8] == 0)
		stock->stock_il = ft_find_u(stock, 0);
	else
	{
		if (ft_find_u(stock, 1) == -1)
			ft_putstr(ft_case_lu_signed(stock), stru);
		else
			stock->stock_il = ft_find_u(stock, 1);
	}
	ft_indic_di(stru, stock);
}
