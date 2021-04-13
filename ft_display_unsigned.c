/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:59:07 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/12 23:01:24 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_handle_prec_u(int size, t_flags *flags)
{
	if ((flags->num_before != 0) && (flags->num_after == 0))
	{
		if ((flags->zero == 1) && (flags->dot == 0))
			ft_write_width('0', flags->num_before, size);
		if (((flags->zero == 1) && (flags->dot == 1)) || (flags->zero == 0))
			ft_write_width(' ', flags->num_before, size);
	}
	if ((flags->num_before != 0) && (flags->num_after != 0))
	{
		if ((flags->num_after < flags->num_before) &&
		(flags->num_after <= size))
			ft_write_width(' ', flags->num_before, size);
		if ((flags->num_after < flags->num_before) && (flags->num_after > size))
			ft_write_width(' ', flags->num_before, flags->num_after);
		if (flags->num_after > flags->num_before)
			ft_write_width('0', flags->num_after, size);
	}
}

int					ft_handle_width_u(int size, t_flags *flags)
{
	if ((flags->num_before == 0) && (flags->num_after != 0))
		ft_write_width('0', flags->num_after, size);
	if ((flags->num_before != 0) && (flags->num_after != 0))
	{
		if (flags->num_after < flags->num_before)
			ft_write_width('0', flags->num_after, size);
		if (flags->num_after > flags->num_before)
			ft_write_width('0', flags->num_before, size);
	}
	return (0);
}

int					ft_display_prec_width_u(unsigned int nb,
unsigned int size, t_flags flags)
{
	if (flags.minus == 1)
	{
		ft_handle_width(size, nb, &flags);
		if (flags.num_after > flags.num_before)
			ft_handle_prec_u(size, &flags);
		ft_putnbr_u(nb);
		if (flags.num_after < flags.num_before)
			ft_handle_prec_u(size, &flags);
		return (0);
	}
	if (flags.minus == 0)
	{
		ft_handle_prec_u(size, &flags);
		if (flags.num_after > flags.num_before)
			ft_handle_width_u(size, &flags);
		if (flags.num_after < flags.num_before)
			ft_handle_width_u(size, &flags);
		ft_putnbr_u(nb);
	}
	return (0);
}

void				ft_display_prec_u(unsigned int nb,
unsigned int size, t_flags flags)
{
	if ((flags.num_before == 0) && (flags.num_after == 0))
		ft_putnbr_u(nb);
	if ((flags.num_before != 0) && (flags.num_after == 0))
	{
		if (flags.minus == 0)
			ft_handle_prec_u(size, &flags);
		ft_putnbr_u(nb);
		if (flags.minus == 1)
			ft_handle_prec_u(size, &flags);
	}
}

int					ft_display_unsigned(unsigned int n, t_flags flags)
{
	unsigned int	nb;
	int					size;

	nb = (unsigned int)n;
	size = ft_get_size_u(nb);
	if ((ft_check_exceptions_zero(nb, flags) == 1))
		return (0);
	if ((flags.num_before == 0) && (flags.num_after == 0))
		ft_display_prec_u(nb, size, flags);
	if ((flags.num_before != 0) && (flags.num_after == 0))
		ft_display_prec_u(nb, size, flags);
	if ((flags.num_before == 0) && (flags.num_after != 0))
	{
		ft_handle_width_u(size, &flags);
		ft_putnbr_u(nb);
	}
	if ((flags.num_before != 0) && (flags.num_after != 0))
		ft_display_prec_width_u(nb, size, flags);
	return (0);
}
