/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:01:35 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/02 13:47:38 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_handle_flags_hexa(int size, t_flags *flags)
{
	int		i;

	i = 0;
	if (flags->num_after > size)
		i =ft_write_width('0', flags->num_after, size);
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

int			ft_display_hexa(unsigned int n, t_flags flags)
{
	char	*res;
	int		size;

	if (flags.hash == 1 && n != 0)
		ft_putstr("0x");
	res = ft_convert(n, "0123456789abcdef");
	size = (int)(ft_strlen(res));
	if (flags.dot == 1)
	{
		if (flags.minus == 0)
		{
			if ((flags.num_after > size) && (flags.num_before > flags.num_after))
			{
				size += ft_write_width(' ', flags.num_before, flags.num_after);
				size += ft_write_width('0', flags.num_before, size);
				ft_putstr(res);
				free(res);
				return (size);
			}
			if (((flags.num_after > 0) && (flags.num_before == 0) && (flags.num_after > size))
			|| ((flags.num_after > size) && (flags.num_before < flags.num_after)))
			{
				size += ft_write_width('0', flags.num_after, size);
				ft_putstr(res);
				free(res);
				return (size);
			}
			else
			{
				if ((flags.minus == 0) || (flags.num_after > size))
				{
					if (flags.num_after > size)
						size = flags.num_after;
					size += ft_handle_flags_hexa(size, &flags);
					ft_putstr(res);
					free(res);
					return (size);
				}
			}
		}
		if (flags.minus == 1)
		{
			ft_putstr(res);
			size += ft_handle_flags_hexa(size, &flags);
		}
	}
	if (flags.dot == 0)
	{
		if (flags.minus == 0)
			size += ft_handle_flags_hexa(size, &flags);
		ft_putstr(res);
		if (flags.minus == 1)
			size += ft_handle_flags_hexa(size, &flags);
	}
	free(res);
	return (size);
}
