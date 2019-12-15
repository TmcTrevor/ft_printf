/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:48:19 by mokhames          #+#    #+#             */
/*   Updated: 2019/12/04 20:48:57 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_percent_sign_left_align(t_struct *f)
{
	f->len += write(f->fd, "%", 1);
	while (f->width > 1)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

static void	ft_print_percent_sign_right_align(t_struct *f)
{
	while (f->width > 1)
	{
		if (f->zero)
			f->len += write(f->fd, "0", 1);
		else
			f->len += write(f->fd, " ", 1);
		f->width--;
	}
	f->len += write(f->fd, "%", 1);
}

void		ft_print_percent_sign(t_struct *f)
{
	if (f->minus)
		ft_print_percent_sign_left_align(f);
	else
		ft_print_percent_sign_right_align(f);
}
