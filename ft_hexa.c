/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:58:50 by jebrocho          #+#    #+#             */
/*   Updated: 2019/01/19 17:00:36 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		ft_putstr_free(char *s, t_struct *stru)
{
	long i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], stru);
		i++;
	}
	free(s);
}

static char		*ft_toupper_mod(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 97 && s[i] <= 122)
			s[i] = s[i] - 32;
		i++;
	}
	return (s);
}

char	*ft_convert_hexa(long long hexa)
{
	int		rest;
	char	*str;
	int		i;

	if (!(str = (char*)malloc(sizeof(char) * 17)))
		return (0);
	i = 0;
	while (hexa != 0)
	{
		rest = hexa % 16;
		if (rest < 10)
			str[i] = rest + 48;
		else
			str[i] = rest + 87;
		hexa = hexa / 16;
		i++;
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}

void	ft_indic_x(t_struct *stru, t_stock *stock)
{
	if (stru->flag[8] == 1)
	{
		if (stru->indic == 'x')
		{
			stock->stock_s = ft_convert_hexa(stock->stock_il);
			ft_putstr_free(ft_convert_hexa(stock->stock_il), stru);
		}
		else
			ft_putstr_free(ft_toupper_mod(ft_convert_hexa(stock->stock_il)), stru);
		return ;
	}
	if (stru->flag[7] == 1)
	{
		if (stru->indic == 'x')
			ft_putstr_free(ft_convert_hexa(stock->stock_ill), stru);
		else
			ft_putstr_free(ft_toupper_mod(ft_convert_hexa(stock->stock_ill)), stru);
		return ;
	}
	if (stru->indic == 'x')
	{
		stock->stock_s = ft_convert_hexa(stock->stock_il);
		ft_indic_s(stru, stock);
	}
	else
		ft_putstr_free(ft_toupper_mod(ft_convert_hexa(stock->stock_il)), stru);
}
