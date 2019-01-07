/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:57:48 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/07 14:40:57 by ezonda           ###   ########.fr       */
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
	int			flag[10]; // 0 / # / - / + /' '/ hh / h / ll / l / L //
}	t_struct;

void	ft_find_indicator(const char *format, t_struct *stru);
void	ft_check_flags(const char *format, t_struct *stru);
void	ft_check_flags_p2(const char *format, t_struct *stru, int i);
void	ft_check_width(const char *format, t_struct *stru);
void	ft_check_precision(const char *format, t_struct *stru);
void	ft_dispatch(t_struct *stru);
void	ft_indic_c(t_struct *stru);
void	ft_initialize_flags(t_struct *stru);

#endif

