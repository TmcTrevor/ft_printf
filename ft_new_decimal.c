/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:18:22 by mokhames          #+#    #+#             */
/*   Updated: 2019/12/14 22:28:03 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_display_sign(int nb, t_struct *f)
{
	if (nb < 0)
		f->len += ft_putstr2("-");
}

static int		ft_pad(t_struct *f, int size, int nb, int a)
{
	int width;

	if (f->width <= 0)
		return (size);
	width = 0;
	if (f->width == 1 && f->precision == 0 && nb == 0 &&
			!f->zero && !f->minus && f->precision_specified)
		width = -1;
	if (!f->minus && f->precision < f->width && f->precision > a && nb < 0
			&& f->precision_specified && f->precision)
		width++;
	if (f->minus && f->precision > a && nb < 0 &&
			f->precision_specified && f->precision)
		width++;
	while (width++ < f->width - size)
	{
		if ((f->zero && !f->minus))
			f->len += ft_putstr2("0");
		else
			f->len += ft_putstr2(" ");
	}
	return (size + width - 1);
}

static int		ft_display_d(t_struct *f, int size, int precision, int nb)
{
	int width_size;
	int width;
	int a;

	width = 0;
	a = ft_num_of_digits(nb, 10);
	width_size = 0;
	if (!f->minus)
	{
		if (f->width && f->zero)
			ft_display_sign(nb, f);
		width_size = ft_pad(f, size, nb, a) - size;
	}
	if ((f->width && (f->minus || !f->zero)) || !f->width)
		ft_display_sign(nb, f);
	if (nb < 0)
		width--;
	while (width++ < precision)
		f->len += ft_putstr2("0");
	if (nb == 0 && f->precision == 0 && f->precision_specified)
		ft_putstr2("");
	else if (size > 0)
		f->len += ft_itoa_base(nb, 10);
	return (size + width_size);
}

static int		type_d(int nb, t_struct *f)
{
	int				size;
	int				precision;
	int				a;

	if (f->precision != 0)
		f->zero = 0;
	size = 0;
	size = ft_num_of_digits(nb, 10);
	a = ft_num_of_digits(nb, 10);
	if (!nb && !f->precision && f->width > size &&
			f->precision_specified && !f->zero && !f->minus)
		f->width++;
	precision = f->precision - size;
	size = (f->precision > size) ? f->precision : size;
	size = (f->precision == -1 && nb == 0) ? 0 : size;
	size = ft_display_d(f, size, precision, nb);
	size = (f->minus) ? ft_pad(f, size, nb, a) : size;
	return (size);
}

void			ft_print_decimal(t_struct *f, va_list ap)
{
	long nbr;

	if (f->nash == 1)
		nbr = va_arg(ap, int);
	if (f->op == 1)
		nbr = va_arg(ap, int);
	nbr = va_arg(ap, int);
	if (f->minus && f->precision_specified && !f->precision && !nbr)
		f->width++;
	type_d(nbr, f);
}
