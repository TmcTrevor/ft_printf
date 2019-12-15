/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:00:00 by mokhames          #+#    #+#             */
/*   Updated: 2019/12/04 20:04:31 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_ret(int e)
{
	if (e >= 10)
		return (97 + e - 10);
	else
		return (e + '0');
}

static char		*ft_struppercase(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 97 && s[i] <= 122)
			s[i] -= 32;
		i++;
	}
	return (s);
}

int				ft_hexa(unsigned int nb, int x, int base)
{
	unsigned int	n2;
	int				i;
	char			*s;
	int				e;

	n2 = nb;
	i = 0;
	while (n2 != 0)
	{
		n2 /= base;
		i++;
	}
	s = (char *)malloc(i * sizeof(char));
	s[i] = 0;
	while (i > 0)
	{
		e = nb % base;
		nb /= base;
		s[i - 1] = ft_ret(e);
		i--;
	}
	if (x == 'X')
		s = ft_struppercase(s);
	ft_putstr2(s);
	return (ft_strlen(s));
}
