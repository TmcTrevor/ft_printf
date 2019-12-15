/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edit_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:51:42 by mokhames          #+#    #+#             */
/*   Updated: 2019/12/14 14:15:42 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_precision(const char *format, t_struct *f, va_list ap)
{
	int precision;

	if (format[f->i] == '.')
	{
		f->i++;
		f->precision_specified = 1;
		if (ft_isdigit(format[f->i]))
		{
			f->precision = ft_atoi(&format[f->i]);
			while (ft_isdigit(format[f->i]))
				f->i++;
		}
		else if (format[f->i] == '*')
		{
			f->nash = 1;
			precision = va_arg(ap, int);
			if (precision >= 0)
				f->precision = precision;
			else
				f->precision_specified = 0;
			while (format[f->i] == '*')
				f->i++;
		}
	}
}

static void	ft_width(const char *format, t_struct *f, va_list ap)
{
	if (format[f->i] == '*')
	{
		f->width = va_arg(ap, int);
		f->minus = (f->width < 0) ? 1 : f->minus;
		f->width = (f->width < 0) ? -f->width : f->width;
		f->op = 1;
		while (format[f->i] == '*')
			f->i++;
	}
	if (ft_isdigit(format[f->i]))
	{
		f->width = ft_atoi(&format[f->i]);
		while (ft_isdigit(format[f->i]))
		{
			f->i++;
			if (format[f->i] == '*')
			{
				f->width = va_arg(ap, int);
				f->width = (f->width < 0) ? -f->width : f->width;
				while (format[f->i] == '*')
					f->i++;
			}
		}
	}
}

static void	ft_flags(const char *format, t_struct *f)
{
	while (ft_strchr("-0", format[f->i]))
	{
		if (format[f->i] == '-')
			f->minus = 1;
		else if (format[f->i] == '0')
			f->zero = 1;
		f->i++;
	}
}

void		ft_edit_flags(const char *format, t_struct *f, va_list ap)
{
	ft_flags(format, f);
	ft_width(format, f, ap);
	ft_precision(format, f, ap);
}
