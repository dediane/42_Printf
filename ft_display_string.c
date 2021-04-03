/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:54:56 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/03 16:29:53 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*int		ft_handle_flag_dot_zero(const char *s, t_flags *flags, int size)
{
	if (((flags->minus == 0) || (flags->minus == 1)) &&
	(flags->num_before < size))
	{
		ft_putstr(s);
		return (size);
	}
	if ((flags->minus == 0) && (flags->num_before > size))
	{
		ft_write_width(' ', flags->num_before, size);
		ft_putstr(s);
		return (flags->num_before);
	}
	if ((flags->minus == 1) && (flags->num_before > size))
	{
		ft_putstr(s);
		ft_write_width(' ', flags->num_before, size);
		return (flags->num_before);
	}
	return (0);
}*/

/*int		ft_handle_flag_dot_nominus(const char *s, t_flags *flags, int size)
{
	if (flags->num_before < flags->num_after)
	{
		if (flags->num_after < size)
		{
			ft_putnchr(s, flags->num_after);
			return (flags->num_after);
		}
		else
			ft_putstr(s);
	}
	if (flags->num_before == flags->num_after)
	{
		ft_write_width(' ', flags->num_before, size);
			if (flags->num_after < size)
			{
				ft_putnchr(s, flags->num_after);
				return (flags->num_after);
			}
		ft_putstr(s);
		return (flags->num_before);
	}
	if (flags->num_before > flags->num_after)
	{
		if (flags->num_after < size)
		{
			ft_write_width(' ', flags->num_before, flags->num_after);
			ft_putnchr(s, flags->num_after);
		}
		if (flags->num_after > size)
		{
			ft_write_width(' ', flags->num_before, size);
			ft_putstr(s);
		}
		return (flags->num_before);
	}
	return (size);
}*/

/*int		ft_handle_flag_dot_minus(const char *s, t_flags *flags, int size)
{
	if (flags->num_before < flags->num_after)
	{
		if (flags->num_after < size)
		{
			ft_putnchr(s, flags->num_after);
			return (flags->num_after);
		}
		else
			ft_putstr(s);
	}
	if (flags->num_before > flags->num_after)
	{
		if (flags->num_after < size)
		{
			ft_putnchr(s, flags->num_after);
			ft_write_width(' ', flags->num_before, flags->num_after);
		}
		if (flags->num_after > size)
		{
			ft_putstr(s);
			ft_write_width(' ', flags->num_before, size);
		}
		return (flags->num_before);
	}
	return (0);
}*/

int				ft_handle_prec_str(int size, t_flags *flags)
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
		if (flags->num_after < size)
			ft_write_width(' ', flags->num_before, flags->num_after);
		else
			ft_write_width(' ', flags->num_before, size);
	}
	return (0);
}

int		ft_display_string(const char *s, t_flags flags)
{
	int size;

	if (s == NULL)
	{
		if ((flags.num_before != 0) && (flags.dot == 1) && (flags.num_after == 0)) 
			s = " ";
		else
			s = "(null)";
	}
	size = ft_strlen(s);
	if (flags.num_before == 0 && flags.num_after == 0)
	{
		if (flags.dot != 1)
			ft_putstr(s);
		return (0);
	}
	if (flags.minus == 0)
	{
		ft_handle_prec_str(size, &flags);
		if ((flags.num_after >= size) || (flags.num_after == 0))
			ft_putstr(s);
		if ((flags.num_after < size) && (flags.num_after != 0))
			ft_putnchr(s, flags.num_after);
	}
	if (flags.minus == 1)
	{
		if ((flags.num_after >= size) || (flags.num_after == 0))
			ft_putstr(s);
		if ((flags.num_after < size) && (flags.num_after != 0))
			ft_putnchr(s, flags.num_after);
		ft_handle_prec_str(size, &flags);
	}
	/*if (flags->dot == 0)
		size = ft_handle_flag_dot_zero(s, flags, size);
	if (flags->dot == 1)
	{
		if ((flags->num_after == 0) && (flags->num_before == 0))
			return (0);
		if (flags->minus == 0)
			size = ft_handle_flag_dot_nominus(s, flags, size);
		if (flags->minus == 1)
			size = ft_handle_flag_dot_minus(s, flags, size);
	}*/
	return (0);
}
