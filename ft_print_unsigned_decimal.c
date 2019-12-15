/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:00:41 by mokhames          #+#    #+#             */
/*   Updated: 2019/12/14 22:19:24 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_unsigned_decimal_left_align(unsigned int nbr, t_struct *f)
{
	int nbrlen;

	nbrlen = ft_num_of_digits(nbr, 10);
	if (nbr == 0 && f->precision_specified && !f->precision)
	{
		while (f->width)
		{
			f->len += write(f->fd, " ", 1);
			f->width--;
		}
		return ;
	}
	while (nbrlen++ < f->precision)
		f->len += write(f->fd, "0", 1);
	f->len += ft_uitoa_base(0, nbr, 10);
	while (f->width >= nbrlen)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

static void	ft_padding(int nbrlen, t_struct *f)
{
	if (!f->precision_specified)
		while (f->width-- > nbrlen)
		{
			if (f->zero)
				f->len += write(f->fd, "0", 1);
			else
				f->len += write(f->fd, " ", 1);
		}
	else
	{
		while (f->width-- > nbrlen)
		{
			if (f->zero)
				f->len += write(f->fd, "0", 1);
			else
				f->len += write(f->fd, " ", 1);
		}
	}
}

static void	ft_print_unsigned_decimal_right_align(unsigned int nbr, t_struct *f)
{
	int nbrlen;

	nbrlen = ft_num_of_digits(nbr, 10);
	if (f->precision_specified && f->precision && f->precision >= f->width)
		f->width = 0;
	if (f->precision > nbrlen)
		f->width -= f->precision - 1;
	if (nbr == 0 && f->precision_specified && !f->precision)
	{
		while (f->width)
		{
			f->len += write(f->fd, " ", 1);
			f->width--;
		}
		return ;
	}
	ft_padding(nbrlen, f);
	while (nbrlen++ < f->precision)
		f->len += write(f->fd, "0", 1);
	f->len += ft_uitoa_base(0, nbr, 10);
}

void		ft_print_unsigned_decimal(t_struct *f, va_list ap)
{
	unsigned int nbr;

	if (f->nash == 1)
		nbr = (unsigned int)va_arg(ap, unsigned int);
	if (f->op == 1)
		nbr = (unsigned int)va_arg(ap, unsigned int);
	nbr = (unsigned int)va_arg(ap, unsigned int);
	if (f->minus)
		ft_print_unsigned_decimal_left_align(nbr, f);
	else
		ft_print_unsigned_decimal_right_align(nbr, f);
}
