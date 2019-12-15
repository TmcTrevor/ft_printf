/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:45:59 by mokhames          #+#    #+#             */
/*   Updated: 2019/12/14 22:18:29 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_nbr(unsigned long long nbr, t_struct *f, char letter)
{
	if (nbr == 0)
		f->len += ft_putstr2("0");
	else
		f->len += ft_hexa(nbr, letter, 16);
}

static void	ft_print_hex_left_align(unsigned int nbr, t_struct *f, char letter)
{
	int nbrlen;

	f->width++;
	nbrlen = ft_ultoa_base2(letter, nbr, 16);
	if (nbr == 0 && f->precision_specified && !f->precision)
	{
		while (f->width-- > 1)
			f->len += write(f->fd, " ", 1);
		return ;
	}
	while (nbrlen++ < f->precision)
		f->len += write(1, "0", 1);
	ft_write_nbr(nbr, f, letter);
	while (f->width-- > nbrlen)
		f->len += write(1, " ", 1);
}

static void	ft_padding(int nbrlen, t_struct *f)
{
	if (!f->precision_specified)
		while (f->width-- > nbrlen)
		{
			if (f->zero)
				f->len += write(1, "0", 1);
			else
				f->len += write(1, " ", 1);
		}
	else
	{
		while (f->width-- > nbrlen)
		{
			if (f->zero)
				f->len += write(1, "0", 1);
			else
				f->len += write(1, " ", 1);
		}
	}
}

static void	ft_print_hex_right_align(unsigned int nbr, t_struct *f, char letter)
{
	int nbrlen;

	nbrlen = ft_ultoa_base2(letter, nbr, 16);
	if (f->precision_specified && f->precision && f->precision >= f->width)
		f->width = 0;
	if (f->precision > nbrlen)
		f->width -= f->precision - nbrlen;
	if (nbr == 0 && f->precision_specified && !f->precision)
	{
		while (f->width--)
			f->len += write(f->fd, " ", 1);
		return ;
	}
	ft_padding(nbrlen, f);
	while (nbrlen++ < f->precision)
		f->len += write(f->fd, "0", 1);
	ft_write_nbr(nbr, f, letter);
}

void		ft_print_hex(char type, t_struct *f, va_list ap)
{
	unsigned int nbr;

	if (f->nash == 1)
		nbr = va_arg(ap, unsigned int);
	if (f->op)
		nbr = va_arg(ap, unsigned int);
	nbr = va_arg(ap, unsigned int);
	if (f->minus)
		ft_print_hex_left_align(nbr, f, type);
	else
		ft_print_hex_right_align(nbr, f, type);
}
