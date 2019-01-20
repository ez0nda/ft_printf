/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:57:48 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/19 17:39:23 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_struct
{
	va_list		ap;
	char		indic;
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
	void		*stock_p;
}	t_stock;

int		ft_printf(const char *format, ...);
void	ft_find_indicator(const char *format, t_struct *stru);
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
void	ft_indic_p(t_struct *stru, t_stock *stock);
void	ft_indic_u(t_struct *stru, t_stock *stock);
void	ft_indic_mod(t_struct *stru);
void	ft_initialize_flags(t_struct *stru);
int		ft_nbrsize(long nb);
void	ft_stock(t_stock *stock, t_struct *stru);
void	ft_apply_flags(t_struct *stru, t_stock *stock);
void	ft_apply_flags2(t_struct *stru, t_stock *stock, int i);
void	ft_apply_flags3(t_struct *stru, t_stock *stock, int i);
void	ft_apply_flags4(t_struct *stru, t_stock *stock);
char	*ft_convert_o(long long octal_int);
char	*ft_convert_hexa(long long hexa);
void	ft_indic_o(t_struct *stru, t_stock *stock);
void	ft_indic_x(t_struct *stru, t_stock *stock);
void	ft_indic_f(t_struct *stru, t_stock *stock);
void	ft_putstr_free(char *s, t_struct *stru);
void	ft_print_hexa(t_struct *stru, t_stock *stock);

long	ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_itoa(long n);
void	ft_putchar(char c, t_struct *stru);
void	ft_putnbr(long n, t_struct *stru);
void	ft_putstr(const char *str, t_struct *stru);
char	*ft_strnew(size_t size);
char	*ft_strrev(char *s);
long	ft_strlen(const char *str);
long	ft_recursive_power(long nb, long pow);
char	*ft_strdup(const char *s);
char	*ft_strsub(const char *s, unsigned int start, size_t len);

#endif

