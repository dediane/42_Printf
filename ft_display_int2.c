/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:09:14 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/19 18:34:49 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_handle_prec(int size, int nb, t_flags flags)
{
	if ((flags.num_before != 0) && (flags.num_after == 0))
	{
		if ((flags.zero == 1) && (flags.dot == 0))
			ft_write_width('0', flags.num_before, size);
		if (((flags.zero == 1) && (flags.dot == 1)) || (flags.zero == 0))
			ft_write_width(' ', flags.num_before, size);
	}
	if ((flags.num_before != 0) && (flags.num_after != 0))
		ft_prec_func(size, nb, flags);
}

void		ft_prec_func(int size, int nb, t_flags flags)
{
	if ((flags.num_after <= flags.num_before) && (flags.num_after < size))
	{
		if ((flags.zero == 1) && (flags.star == 1))
			ft_write_width('0', flags.num_before, size);
		else
			ft_write_width(' ', flags.num_before, size);
	}
	if ((flags.num_after < flags.num_before) && (flags.num_after >= size))
		ft_prec_func2(nb, flags);
	if (((flags.num_after > flags.num_before) && (flags.star == 0))
			|| ((flags.num_after == flags.num_before) && (flags.star == 0)))
	{
		if (nb < 0)
			size--;
		ft_write_width('0', flags.num_after, size);
	}
}

void		ft_prec_func2(int nb, t_flags flags)
{
	if ((flags.zero == 1) && (flags.star == 1))
	{
		if (nb < 0)
			ft_write_width('0', flags.num_before, flags.num_after + 1);
		else
			ft_write_width('0', flags.num_before, flags.num_after);
	}
	else
	{
		if (nb < 0)
			ft_write_width(' ', flags.num_before, flags.num_after + 1);
		else
			ft_write_width(' ', flags.num_before, flags.num_after);
	}
}

void		ft_handle_width(int size, int nb, t_flags flags)
{
	if ((flags.num_before == 0) && (flags.num_after != 0) && (flags.star == 0))
		ft_write_width('0', flags.num_after, size);
	if ((flags.num_before != 0) && (flags.num_after != 0))
		ft_handle_width2(size, nb, flags);
}

void		ft_handle_width2(int size, int nb, t_flags flags)
{
	if (flags.num_after < flags.num_before)
	{
		if (nb < 0)
			size--;
		if ((flags.star == 0) || ((flags.star == 1) && (flags.zero == 1)))
			ft_write_width('0', flags.num_after, size);
		else if (flags.star == 1)
			ft_write_width(' ', flags.num_after, size);
	}
	if ((flags.num_after == flags.num_before) && (flags.star == 1))
	{
		if ((nb < 0) && (flags.star == 0))
			size++;
		if (flags.zero == 1)
			ft_write_width('0', flags.num_after, size);
		else
			ft_write_width(' ', flags.num_after, size);
	}
	if ((flags.num_after > flags.num_before) && (flags.star == 1))
	{
		size++;
		ft_write_width(' ', flags.num_after, size);
	}
}
