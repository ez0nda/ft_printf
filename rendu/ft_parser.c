/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 09:59:40 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/17 15:33:25 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_find_indicator(const char *format, t_struct *stru, t_stock *stock)
{
	int		i;

	i = 0;
	ft_initialize_flags(stru);
	while (format[i] != 'd' && format[i] != 'i' && format[i] != 'o' &&
			format[i] != 'u' && format[i] != 'x' && format[i] != 'X' &&
			format[i] != 'c' && format[i] != 's' && format[i] != 'p' &&
			format[i] != 'f')
		i++;
	stru->indic = format[i];
	ft_stock(stock, stru);
}

void	ft_check_flags(const char *format, t_struct *stru, t_stock *stock)
{
	int i;

	i = 0;
	while (format[i] != 'd' && format[i] != 'i' && format[i] != 'o' &&
			format[i] != 'u' && format[i] != 'x' && format[i] != 'X' &&
			format[i] != 'c' && format[i] != 's' && format[i] != 'p' &&
			format[i] != 'f')
	{
		if (format[i] == '0' && (format[i - 1] < '0' || format[i - 1] > '9'))
			stru->flag[0] = 1;
		if (format[i] == '#')
			stru->flag[1] = 1;
		if (format[i] == '-')
			stru->flag[2] = 1;
		if (format[i] == '+')
			stru->flag[3] = 1;
		if (format[i] == ' ')
			stru->flag[4] = 1;
		ft_check_flags_p2(format, stru, i);
		i++;
	}
	ft_dispatch(stru, stock);
}

void	ft_check_flags_p2(const char *format, t_struct *stru, int i)
{
	if (format[i] == 'h' && format[i + 1] == 'h')
		stru->flag[5] = 1;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		stru->flag[6] = 1;
	if (format[i] == 'l' && format[i + 1] == 'l')
		stru->flag[7] = 1;
	else if (format[i] == 'l' && format[i + 1] != 'l')
		stru->flag[8] = 1;
	if (format[i] == 'L')
		stru->flag[9] = 1;
}

void	ft_check_width(const char *format, t_struct *stru)
{
	int		i;
	int		j;
	char	*width;

	i = 0;
	j = 0;
	width = ft_strnew(0);
	while (format[i] != stru->indic && format[i] != '.')
	{
		if (ft_isdigit(format[i]) && format[i] != stru->indic)
		{
			width[j] = format[i];
			j++;
		}
		i++;
		width[j] = '\0';
	}
	stru->min_field = ft_atoi(width);
	free(width);
}

void	ft_check_precision(const char *format, t_struct *stru)
{
	int		i;
	int		j;
	char	*pre;

	i = 0;
	j = 0;
	pre = ft_strnew(0);
	stru->prec = 0;
	while (format[i] != '\0' && format[i] != stru->indic)
	{
		if (format[i] == '.' && ft_isdigit(format[i + 1]))
		{
			while (ft_isdigit(format[++i]))
				pre[j++] = format[i];
		}
		i++;
		pre[j] = '\0';
	}
	stru->prec = ft_atoi(pre);
	free(pre);
}
