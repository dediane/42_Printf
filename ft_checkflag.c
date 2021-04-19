/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:27:36 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/19 15:32:11 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_handle_star(t_flags *flags)
{
	if (flags->num_after < 0)
	{
		flags->num_after *= -1;
		flags->star = 1;
	}
	if (flags->num_before < 0)
	{
		flags->num_before *= -1;
		flags->minus = 1;
		flags->zero = 0;
	}
}

void		ft_handle_minus(t_flags *flags)
{
	flags->minus = 1;
	if (flags->zero == 1)
		flags->zero = 0;
}

void		ft_checkflag(char current, t_flags *flags, va_list args)
{
	if (current == '-')
		ft_handle_minus(flags);
	if (current == '*')
	{
		if (flags->dot == 1)
			flags->num_after = va_arg(args, int);
		else
			flags->num_before = va_arg(args, int);
		ft_handle_star(flags);
	}
	if ((current == '0') && (flags->num_before == 0) && (flags->num_after == 0))
		flags->zero = 1;
	if ((current == '0') && (flags->dot == 1) && (flags->num_after != 0))
		flags->num_after = (flags->num_after * 10) + (int)current - 48;
	if ((current == '0') && (flags->dot == 0) && (flags->num_before != 0))
		flags->num_before = (flags->num_before * 10) + (int)current - 48;
	if (current == '.')
		flags->dot = 1;
	if ((current > '0' && current <= '9') && (flags->dot == 1))
		flags->num_after = (flags->num_after * 10) + (int)current - 48;
	if ((current > '0' && current <= '9') && (flags->dot == 0))
		flags->num_before = (flags->num_before * 10) + (int)current - 48;
}
