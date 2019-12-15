/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:55:03 by mokhames          #+#    #+#             */
/*   Updated: 2019/12/04 20:57:38 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_string_left(char *str, t_struct *f)
{
	int i;

	if (!str)
		str = "(null)";
	i = ft_strlen(str);
	if (f->precision_specified && i > f->precision)
		i = f->precision;
	f->len += ft_putstr3(str, i);
	while (f->width > i)
	{
		f->len += write(1, " ", 1);
		f->width--;
	}
}

static void		ft_print_string_right(char *str, t_struct *f)
{
	int i;

	if (!str)
		str = "(null)";
	i = ft_strlen(str);
	if (f->precision_specified && i > f->precision)
		i = f->precision;
	while (f->width > i)
	{
		if (f->zero)
			f->len += write(1, "0", 1);
		else
			f->len += write(1, " ", 1);
		f->width--;
	}
	f->len += ft_putstr3(str, i);
}

void			ft_print_string(t_struct *f, va_list ap)
{
	char *str;

	if (f->nash == 1)
		va_arg(ap, int);
	if (f->op == 1)
		va_arg(ap, int);
	str = va_arg(ap, char *);
	if (f->minus)
		ft_print_string_left(str, f);
	else
		ft_print_string_right(str, f);
}
