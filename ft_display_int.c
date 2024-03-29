/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:59:48 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/19 18:38:42 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_display_prec_width2(int nb, int size, t_flags flags)
{
	if (nb < 0)
		ft_putchar('-');
	if ((flags.star == 0) || ((flags.star == 1) && (flags.minus == 0)))
		ft_handle_width(size, nb, flags);
	if (flags.num_after >= flags.num_before)
		ft_handle_prec(size, nb, flags);
	ft_putnbr(nb);
	if (flags.num_after < flags.num_before)
		ft_handle_prec(size, nb, flags);
	if ((flags.star == 1) && (flags.minus == 1))
		ft_handle_width(size, nb, flags);
}

void			ft_display_prec_width3(int nb, int size, t_flags flags)
{
	if ((nb < 0) && ((flags.zero == 1) &&
				(size < flags.num_before) && (flags.star == 1)))
		ft_putchar('-');
	ft_handle_prec(size, nb, flags);
	if (flags.num_after >= flags.num_before)
		ft_handle_width(size, nb, flags);
	if ((nb < 0) && ((size >= flags.num_before) ||
				(flags.zero == 0) || flags.star == 0))
		ft_putchar('-');
	if (flags.num_after < flags.num_before)
		ft_handle_width(size, nb, flags);
	ft_putnbr(nb);
}

int				ft_display_prec_width(int nb, int size, t_flags flags)
{
	if ((nb < 0) && (flags.star == 1) && (flags.num_after > size)
			&& (flags.minus == 0))
	{
		ft_handle_prec(size, nb, flags);
		ft_handle_width(size, nb, flags);
		ft_putchar('-');
		ft_putnbr(nb);
		return (0);
	}
	if ((flags.minus == 1) || ((flags.num_after >= flags.num_before)))
	{
		ft_display_prec_width2(nb, size, flags);
		return (0);
	}
	if (flags.minus == 0)
		ft_display_prec_width3(nb, size, flags);
	return (0);
}

void			ft_display_prec(int nb, int size, t_flags flags)
{
	if ((flags.num_before == 0) && (flags.num_after == 0))
	{
		if (nb < 0)
			ft_putchar('-');
		ft_putnbr(nb);
	}
	if ((flags.num_before != 0) && (flags.num_after == 0))
	{
		if ((nb < 0) && ((flags.minus == 1) || ((flags.zero == 1) &&
						(size < flags.num_before) && (flags.dot == 0))))
			ft_putchar('-');
		if (flags.minus == 0)
			ft_handle_prec(size, nb, flags);
		if ((nb < 0) && (flags.minus == 0) && ((size >= flags.num_before) ||
					(flags.zero == 0) || (flags.dot == 1)))
			ft_putchar('-');
		ft_putnbr(nb);
		if (flags.minus == 1)
			ft_handle_prec(size, nb, flags);
	}
}

int				ft_display_int(int n, t_flags flags)
{
	long int	nb;
	int			size;

	nb = (long int)n;
	size = ft_get_size(nb);
	if (ft_check_exceptions_zero(nb, flags) == 1)
		return (0);
	if ((flags.num_before == 0) && (flags.num_after == 0))
		ft_display_prec(nb, size, flags);
	if ((flags.num_before != 0) && (flags.num_after == 0))
		ft_display_prec(nb, size, flags);
	if ((flags.num_before == 0) && (flags.num_after != 0))
	{
		if (nb < 0)
		{
			ft_putchar('-');
			size--;
		}
		ft_handle_width(size, nb, flags);
		ft_putnbr(nb);
	}
	if ((flags.num_before != 0) && (flags.num_after != 0))
		ft_display_prec_width(nb, size, flags);
	return (0);
}
