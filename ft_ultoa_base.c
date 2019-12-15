/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:36:08 by mokhames          #+#    #+#             */
/*   Updated: 2019/12/14 14:22:06 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ultoa_base(char c, unsigned long long value, int base)
{
	int					len;
	unsigned long long	value2;
	char				*radix;
	char				*result;

	len = 1;
	value2 = value;
	while (value2 /= base)
		len++;
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	radix = (c == 'X') ? ft_strdup("0123456789ABCDEF") :
		ft_strdup("0123456789abcdef");
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = radix[value % base];
		value /= base;
	}
	len = ft_strlen(result);
	ft_putstr(result);
	free(radix);
	free(result);
	return (len);
}
