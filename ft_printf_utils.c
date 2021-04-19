/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:21:23 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/19 17:45:17 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned int	ft_check_exceptions_zero(unsigned int nb, t_flags flags)
{
	if ((nb == 0) && (flags.dot == 1))
	{
		if ((flags.num_before == 0) && (flags.num_after == 0))
			return (1);
		if ((flags.num_before != 0) && (flags.num_after == 0))
		{
			ft_write_width(' ', flags.num_before, 0);
			return (1);
		}
		if ((flags.num_before == 0) && (flags.num_after != 0)
		&& (flags.star == 0))
		{
			ft_write_width('0', flags.num_after, 0);
			return (1);
		}
		if ((flags.num_before == 0) && (flags.star == 1))
		{
			ft_putchar('0');
			return (1);
		}
	}
	return (0);
}

int				ft_get_size(long int n)
{
	int			size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	size++;
	return (size);
}

int				ft_get_size_u(unsigned int n)
{
	int			size;

	size = 0;
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	size++;
	return (size);
}

int				ft_write_width(char c, int max, int size)
{
	int			i;

	i = 0;
	while (i < (max - size))
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}
