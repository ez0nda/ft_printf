/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:02:16 by ezonda            #+#    #+#             */
/*   Updated: 2019/01/17 11:14:46 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

long	ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_itoa(long n);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(const char *str);
char	*ft_strnew(size_t size);
char	*ft_strrev(char *s);
long	ft_strlen(const char *str);
long	ft_recursive_power(long nb, long pow);

#endif
