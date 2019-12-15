/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_of_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:29:33 by mokhames          #+#    #+#             */
/*   Updated: 2019/12/14 22:29:03 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_num_of_digits(long value, int base)
{
	int		i;

	i = 0;
	if (value == 0)
		return (1);
	if (value < 0)
	{
		i++;
		value *= -1;
	}
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

int		ft_ultoa_base2(char c, unsigned long long value, int base)
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
	free(radix);
	free(result);
	return (len);
}
