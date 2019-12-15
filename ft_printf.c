/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:03:33 by mokhames          #+#    #+#             */
/*   Updated: 2019/12/12 22:28:17 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

static t_struct	*ft_init_list(t_struct *f)
{
	if (!(f = (t_struct *)ft_memalloc(sizeof(t_struct))))
		return (NULL);
	f->i = 0;
	f->len = 0;
	f->op = 0;
	f->nash = 0;
	f->precision = 0;
	return (f);
}

int				ft_printf(const char *format, ...)
{
	int			len;
	t_struct	*f;
	va_list		ap;

	f = NULL;
	if (!(f = ft_init_list(f)))
		return (-1);
	f->fd = 1;
	va_start(ap, format);
	if (format[0] == '%' && !format[1])
		return (0);
	else if (!ft_strchr(format, '%'))
		f->len += ft_putstr2(format);
	else
		ft_check_format(format, f, ap);
	len = f->len;
	free(f);
	va_end(ap);
	return (len);
}
