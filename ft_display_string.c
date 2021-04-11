/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:54:56 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/11 13:30:56 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_handle_prec_s(int size, t_flags *flags)
{
	if ((flags->num_before != 0) && (flags->num_after == 0))
	{
		if ((flags->zero == 1) && (flags->dot == 0) && (flags->minus == 0))
			ft_write_width('0', flags->num_before, size);
		else if (((flags->zero == 1) && (flags->dot == 1)) ||
				(flags->zero == 0))
			ft_write_width(' ', flags->num_before, size);
		else if ((flags->zero == 1) && (flags->dot == 0) && (flags->minus == 1))
			ft_write_width(' ', flags->num_before, size);
	}
	if ((flags->num_before != 0) && (flags->num_after != 0))
	{
		if (flags->num_after < size)
			ft_write_width(' ', flags->num_before, flags->num_after);
		else
			ft_write_width(' ', flags->num_before, size);
	}
	return (0);
}

int				ft_handle_minus_zero_s(int size, const char *s, t_flags flags)
{
	ft_handle_prec_s(size, &flags);
	if ((flags.num_after >= size) || (flags.num_after == 0))
	{
		if ((flags.dot == 0) || ((flags.dot == 1) &&
					(flags.num_after != 0)))
			ft_putstr(s);
	}
	if ((flags.num_after < size) && (flags.num_after != 0))
		ft_putnchr(s, flags.num_after);
	return (0);
}

int				ft_handle_minus_one_s(int size, const char *s, t_flags flags)
{
	if (((flags.num_after >= size) && (flags.num_after != 0)) ||
			(flags.num_after == 0))
	{
		if ((flags.dot == 0) || ((flags.dot == 1) &&
					(flags.num_after != 0)))
			ft_putstr(s);
	}
	if ((flags.num_after < size) && (flags.num_after != 0))
		ft_putnchr(s, flags.num_after);
	ft_handle_prec_s(size, &flags);
	return (0);
}

int				ft_display_string(const char *s, t_flags flags)
{
	int			size;

	if (s == NULL)
	{
		if (flags.num_before != 0 && flags.dot == 1 && flags.num_after == 0)
			s = ft_strdup(" ");
		else
			s = ft_strdup("(null)");
	}
	if ((flags.dot == 1) && (flags.num_before == 0) && (flags.num_after == 0))
		return (0);
	size = ft_strlen(s);
	if ((flags.dot == 1) && (flags.num_after == 0))
		size = 0;
	if (flags.num_before == 0 && flags.num_after == 0)
	{
		if (flags.dot != 1)
			ft_putstr(s);
		return (0);
	}
	if (flags.minus == 0)
		ft_handle_minus_zero_s(size, s, flags);
	if (flags.minus == 1)
		ft_handle_minus_one_s(size, s, flags);
	return (0);
}
