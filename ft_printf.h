/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:57:48 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/12 10:29:57 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_struct
{
	va_list		ap;
	char		indic;
	int			mod;
	int			min_field;
	int			prec;
	int			count_char;
	int			valid;
	int			stock_pre;
	int			stock_pad;
	int			flag[10]; // 0 / # / - / + /' '/ hh / h / ll / l / L //
}	t_struct;

typedef struct s_stock
{
	int		stock_i;
	float	stock_f;
	char	stock_c;
	char	*stock_s;
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
char	*ft_indic_o(int octal_int);
void	ft_apply_flags(t_struct *stru, t_stock *stock);

#endif

