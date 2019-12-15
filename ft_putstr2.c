/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:30:12 by mokhames          #+#    #+#             */
/*   Updated: 2019/12/04 21:38:24 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr2(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int		ft_putstr3(const char *s, int a)
{
	int i;

	i = 0;
	while (s[i] && a)
	{
		ft_putchar(s[i]);
		i++;
		a--;
	}
	return (i);
}
