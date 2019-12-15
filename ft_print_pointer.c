/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:51:03 by mokhames          #+#    #+#             */
/*   Updated: 2019/12/14 22:20:30 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_pointer_left_align(char c, long long nbr, t_struct *f)
{
	int nbrlen;

	nbrlen = ft_ultoa_base2(c, nbr, 16) + 2;
	f->len += write(f->fd, "0x", 2);
	while (f->precision > (nbrlen - 2))
	{
		f->len += write(f->fd, "0", 1);
		f->precision--;
	}
	if (!nbr && !f->precision && f->precision_specified && f->width++)
		ft_putstr2("");
	else
		f->len += ft_ultoa_base(c, nbr, 16);
	while (f->width > nbrlen)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

static void	ft_print_pointer_right_align(char c, long long nbr, t_struct *f)
{
	int nbrlen;

	nbrlen = ft_ultoa_base2(c, nbr, 16) + 2;
	if (nbr == 0 && f->precision_specified)
		nbrlen--;
	while (f->width > nbrlen)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
	f->len += write(f->fd, "0x", 2);
	if (nbr == 0 && f->precision_specified && !f->precision)
		return ;
	while ((nbrlen - 2) < f->precision)
	{
		f->len += write(f->fd, "0", 1);
		nbrlen++;
	}
	f->len += ft_ultoa_base(c, nbr, 16);
}

void		ft_print_pointer(char c, t_struct *f, va_list ap)
{
	long long nbr;

	if (f->nash == 1)
		nbr = (long long)va_arg(ap, void *);
	if (f->op == 1)
		nbr = (long long)va_arg(ap, void *);
	nbr = (long long)va_arg(ap, void *);
	if (f->minus)
		ft_print_pointer_left_align(c, nbr, f);
	else
		ft_print_pointer_right_align(c, nbr, f);
}
