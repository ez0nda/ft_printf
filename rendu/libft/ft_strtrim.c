/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:28:11 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/17 17:43:57 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		n;
	char	*str;

	i = 0;
	j = 0;
	n = 0;
	if (!(s))
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[j])
		j++;
	while (s[j] <= 32)
		j--;
	while (s[i] <= 32)
		i++;
	i--;
	while (i++ < j)
		str[n++] = s[i];
	str[n] = '\0';
	return (str);
}
