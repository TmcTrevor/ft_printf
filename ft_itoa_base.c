/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:14:17 by mokhames          #+#    #+#             */
/*   Updated: 2019/12/04 20:14:32 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long		ft_change(long value, long int *a, int *b, int base)
{
	long i;

	*a = (value < 0) ? -value : value;
	i = *a;
	while (*a /= base)
		*b = *b + 1;
	return (i);
}

int				ft_itoa_base(long value, int base)
{
	int		len;
	long	value2;
	char	*radix;
	char	*result;
	long	a;

	len = 1;
	a = ft_change(value, &value2, &len, base);
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	radix = ft_strdup("0123456789abcdef");
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = radix[a % base];
		a /= base;
	}
	len = ft_strlen(result);
	ft_putstr(result);
	free(radix);
	free(result);
	return (len);
}
