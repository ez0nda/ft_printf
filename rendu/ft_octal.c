/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:33:05 by jebrocho          #+#    #+#             */
/*   Updated: 2019/01/24 01:59:17 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*ft_convert_o(uintmax_t octal_int)
{
	int			i;
	char		*str;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * 23)))
		return (NULL);
	while (octal_int != 0)
	{
		str[i] = octal_int % 8 + 48;
		octal_int /= 8;
		i++;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}

void		ft_izi(t_struct *stru, int i)
{
	if (stru->flag[0] == 0)
		while (stru->min_field-- > i)
			ft_putchar(' ', stru);
	else
		while (stru->min_field-- > i)
			ft_putchar('0', stru);
}

void		ft_has_flag(t_struct *stru, t_stock *stock)
{
	int i;

	if (stock->stock_il != 0)
		i = ft_nbrsize(stock->stock_il) + 1;
	else
		i = ft_nbrsize(stock->stock_il);
	if (stru->flag[2] == 1)
	{
		ft_putchar('0', stru);
		if (stock->stock_il != 0)
		{
			if (stru->flag[7] == 0 && stru->flag[8] == 0)
				ft_putnbr(stock->stock_il, stru);
			else
				ft_putstr(stock->stock_s, stru);
		}
		ft_izi(stru, i);
		return ;
	}
	ft_izi(stru, i);
	ft_putchar('0', stru);
	if (stock->stock_il != 0)
	{
		if (stru->flag[7] == 0 && stru->flag[8] == 0)
			ft_putnbr(stock->stock_il, stru);
		else
			ft_putstr(stock->stock_s, stru);
	}
}

void		ft_indic_o(t_struct *stru, t_stock *stock)
{
	stru->flag[4] = 0;
	stru->flag[3] = 0;
	if (stru->flag[5] == 1)
		stock->stock_h = 256;
	else if (stru->flag[6] == 1)
		stock->stock_h = 65536;
	else
		stock->stock_h = 4294967296;
	if (stock->stock_il >= stock->stock_h && stru->flag[7] == 0 && stru->flag[8] == 0)
		stock->stock_il = stock->stock_il % stock->stock_h;
	if ((stock->stock_s = ft_convert_o(stock->stock_il)) == NULL)
		return ;
	if (stru->flag[7] == 0 && stru->flag[8] == 0)
		stock->stock_il = ft_atoi(stock->stock_s);
	if (stru->flag[1] == 0)
		ft_indic_di(stru, stock);
	else
		ft_has_flag(stru, stock);
	free(stock->stock_s);
}
