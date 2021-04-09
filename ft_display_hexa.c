/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:01:35 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/09 21:45:54 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_handle_flags_hexa(int size, t_flags *flags)
{
	int			i;

	i = 0;
	if (flags->num_after > size)
		i = ft_write_width('0', flags->num_after, size);
	if ((flags->num_before != 0) && (flags->zero == 0) &&
			(flags->num_after < size))
		i = ft_write_width(' ', flags->num_before, size);
	if ((flags->num_before != 0) && (flags->zero == 1))
		i = ft_write_width('0', flags->num_before, size);
	if (flags->num_after != 0)
	{
		while (i < (flags->num_before - size))
		{
			ft_putchar('0');
			i++;
		}
	}
	return (i);
}
int				ft_handle_width_hexa(int size, t_flags *flags)
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
	return(0);

}int				ft_handle_prec_hexa(int size, t_flags *flags)
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
		if ((flags->num_after < flags->num_before) && (flags->num_after < size))
			ft_write_width(' ', flags->num_before, size);
		if ((flags->num_after < flags->num_before) && (flags->num_after > size))
			ft_write_width(' ', flags->num_before, flags->num_after);
		if (flags->num_after > flags->num_before)
			ft_write_width('0', flags->num_after, size);
	}
	return (0);
}



int				ft_display_hexa(unsigned int n, t_flags flags)
{
	char		*res;
	int			size;

	if (flags.hash == 1 && n != 0)
		ft_putstr("0x");
	if (ft_check_exceptions_zero(n, flags) == 1)
		return (0);
	res = ft_convert(n, "0123456789abcdef");
	size = (int)(ft_strlen(res));
	if (flags.minus == 0)
	{
		ft_handle_prec_hexa(size, &flags);
		ft_handle_width_hexa(size, &flags);
		ft_putstr(res);
		free(res);
		return (0);
	}
	if ((flags.minus == 1) && (flags.zero == 0))
	{
		ft_handle_width_hexa(size, &flags);
		if (flags.num_after > flags.num_before)
			ft_handle_prec_hexa(size, &flags);
		ft_putstr(res);
		if (flags.num_after < flags.num_before)
			ft_handle_prec_hexa(size, &flags);
		free(res);
		return (0);
	}
	free(res);
	return (0);
}
