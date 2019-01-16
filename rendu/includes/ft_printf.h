/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:57:48 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/16 12:48:51 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../lib/includes/libftprintf.h"

typedef struct s_struct
{
	va_list		ap;
	char		indic;
	int			mod;
	int			min_field;
	int			prec;
	long		float_dec;
	int			count_char;
	int			valid;
	int			stock_pre;
	int			stock_pad;
	int			flag[10]; // 0 / # / - / + /' '/ hh / h / ll / l / L //
}	t_struct;

typedef struct s_stock
{
	int			stock_i;
	long		stock_il;
	long long	stock_ill;
	double		stock_f;
	long double	stock_lf;
	char		stock_c;
	char		*stock_s;
}	t_stock;

void	ft_find_indicator(const char *format, t_struct *stru, t_stock *stock);
void	ft_check_flags(const char *format, t_struct *stru, t_stock *stock);
void	ft_check_flags_p2(const char *format, t_struct *stru, int i);
void	ft_check_width(const char *format, t_struct *stru);
void	ft_check_precision(const char *format, t_struct *stru);
void	ft_check_format(const char *format, t_struct *stru);
int		ft_check_indic_c(const char *format, t_struct *stru);
int		ft_check_indic_di(const char *format, t_struct *stru);
void	ft_dispatch(t_struct *stru, t_stock *stock);
void	ft_indic_c(t_struct *stru, t_stock *stock);
void	ft_indic_di(t_struct *stru, t_stock *stock);
void	ft_indic_s(t_struct *stru, t_stock *stock);
void	ft_initialize_flags(t_struct *stru);
int		ft_nbrsize(int nb);
void	ft_stock(t_stock *stock, t_struct *stru);
void	ft_apply_flags(t_struct *stru, t_stock *stock);
void	ft_apply_flags2(t_struct *stru, t_stock *stock, int i);
void	ft_apply_flags3(t_struct *stru, t_stock *stock, int i);
void	ft_apply_flags4(t_struct *stru, t_stock *stock);
char	*ft_convert_o(long long octal_int);
void	ft_indic_o(t_struct *stru, t_stock *stock);
void	ft_indic_h(t_struct *stru, t_stock *stock);
void	ft_indic_f(t_struct *stru, t_stock *stock);

#endif

