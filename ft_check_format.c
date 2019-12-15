/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:48:11 by mokhames          #+#    #+#             */
/*   Updated: 2019/12/04 21:30:56 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printf_format(const char *format, t_struct *f, va_list ap)
{
	if (format[f->i] == 'd' || format[f->i] == 'i')
		ft_print_decimal(f, ap);
	else if (format[f->i] == 'u')
		ft_print_unsigned_decimal(f, ap);
	else if (format[f->i] == 'x' || format[f->i] == 'X')
		ft_print_hex(format[f->i], f, ap);
	else if (format[f->i] == 'p')
		ft_print_pointer(format[f->i], f, ap);
	else if (format[f->i] == 'c')
		ft_print_char(f, ap);
	else if (format[f->i] == 's')
		ft_print_string(f, ap);
	else if (format[f->i] == '%')
		ft_print_percent_sign(f);
}

static void		ft_reset_struct(t_struct *f)
{
	f->minus = 0;
	f->zero = 0;
	f->width = 0;
	f->precision_specified = 0;
	f->precision = 0;
	f->nash = 0;
	f->op = 0;
}

void			ft_check_format(const char *format, t_struct *f, va_list ap)
{
	va_list ap1;

	va_copy(ap1, ap);
	while (format[f->i] != '\0')
	{
		if (format[f->i] == '%')
		{
			f->i++;
			if (ft_strchr("-.*0123456789", format[f->i]))
				ft_edit_flags(format, f, ap);
			if (ft_strchr("spdiuxXc%", format[f->i]))
			{
				ft_printf_format(format, f, ap1);
				ft_reset_struct(f);
			}
		}
		else
			f->len += write(1, &format[f->i], 1);
		f->i++;
	}
}
