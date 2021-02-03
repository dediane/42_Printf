/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:59:48 by ddecourt          #+#    #+#             */
/*   Updated: 2021/02/03 23:06:46 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_get_size(long int n)
{
	int			size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n > 10)
	{
		n = n / 10;
		size++;
	}
	size++;
	return (size);
}

int				ft_write_width(char c, int i, int max, int size)
{
	while (i < (max - size))
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

int				ft_handle_flags(int size, t_flags *flags)
{
	int			i;

	i = 0;
	if (flags->num_before != 0)
	{
		if ((flags->zero == 1) && (flags->dot == 0))
			i = ft_write_width('0', 0, flags->num_before, size);
		if ((flags->zero == 1) && (flags->dot == 1))
			i = ft_write_width(' ', 0, flags->num_before, size);
		if (flags->zero == 0)
			i = ft_write_width(' ', 0, flags->num_before, size);
	}
	else if (flags->num_after != 0)
	{
		while (i < (flags->num_before - size))
		{
			ft_putchar('0');
			i++;
		}
	}
	return (i);
}

int				ft_display_int(int n, t_flags flags)
{
	long int	nb;
	int			size;

	nb = (long int)n;
	size = ft_get_size(nb);
	if ((flags.plus == 1) && (n >= 0))
	{
		size++;
		size += ft_handle_flags(size, &flags);
		ft_putchar('+');
		ft_putnbr(n, &flags);
		return (size);
	}
	if (flags.minus == 1)
	{
		ft_putnbr(n, &flags);
		size += ft_handle_flags(size, &flags);
		return (size);
	}
	if ( (flags.zero == 1) && (flags.dot == 1))
	{
		size += ft_handle_flags(size, &flags);
		if (n < 0)
			ft_putchar('-');;
		ft_putnbr(n, &flags);
		return (size);
	}
	if ((nb < 0) && (flags.zero == 1) && (flags.dot == 0))
		ft_putchar('-');
	size += ft_handle_flags(size, &flags);
	ft_putnbr(n, &flags);
	return (size);
}
