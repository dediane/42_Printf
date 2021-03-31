/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:59:48 by ddecourt          #+#    #+#             */
/*   Updated: 2021/03/31 15:35:29 by ddecourt         ###   ########.fr       */
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

int				ft_write_width(char c, int max, int size)
{
	int i;

	i = 0;
	while (i < (max - size))
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

int				ft_handle_flags(int size, t_flags *flags)
{
	if ((flags->num_before != 0) && (flags->num_after == 0))
	{
		if ((flags->zero == 1) && (flags->dot == 0))
			 ft_write_width('0', flags->num_before, size);
		if ((flags->zero == 1) && (flags->dot == 1))
			 ft_write_width(' ', flags->num_before, size);
		if (flags->zero == 0)
			 ft_write_width(' ', flags->num_before, size);
	}
	if (flags->num_after != 0)
	{
		if ((flags->num_before != 0) && (flags->minus == 0))
		{
			if ((flags->num_after < flags->num_before) && (flags->num_after < size))
				 ft_write_width(' ', flags->num_before, size);
			if ((flags->num_after < flags->num_before) && (flags->num_after > size))
			{
				 ft_write_width(' ', flags->num_before, flags->num_after);
			}
		}
		 ft_write_width('0', flags->num_after, size);
		if (flags->minus != 0)
			 ft_write_width(' ', flags->num_before, size);
	}
	return (0);
}

int				ft_display_int(int n, t_flags flags)
{
	long int nb;
	int			size;

	nb = (long int)n;
	size = ft_get_size(nb);
	if (nb < 0 && flags.num_after != 0)
		size--;
	if(flags.minus == 1)
	{
		if (nb < 0)
			ft_putchar('-');
		ft_putnbr(nb);
		size+= ft_handle_flags(size, &flags);
	}
	else
	{
		if (nb < 0 && (flags.zero == 1 || flags.num_after != 0))
		{
			ft_putchar('-');
			 ft_handle_flags(size + 1, &flags);
		}
		if (nb < 0 && (flags.zero == 0 && flags.num_after == 0))
		{
			 ft_handle_flags(size, &flags);
			ft_putchar('-');
		}
		else
		{
			 ft_handle_flags(size, &flags);
		}
		ft_putnbr(nb);
	}
	return (0);
}

/*int				ft_display_int(int n, t_flags flags)
{
	long int	nb;
	int			size;

	nb = (long int)n;
	size = ft_get_size(nb);
	if ((flags.zero == 1) && (nb < 0) && (flags.num_after == 0))
		ft_putchar('-');
	if ((flags.num_before == 0) && (flags.num_after == 0))
		ft_putnbr(nb);
	if ((flags.num_before != 0) && (flags.num_after == 0))
	{
		if (flags.minus == 0)
			 ft_handle_flags(size, &flags);
		if ((flags.zero == 0) && (nb < 0))
			ft_putchar('-');
		ft_putnbr(nb);
		if (flags.minus == 1)
			 ft_handle_flags(size, &flags);
	}
	if (flags.num_after != 0)
	{
		if ((n < 0))
		{
			ft_putchar('-');
			 ft_handle_flags(size - 1, &flags);
		}
		else
			 ft_handle_flags(size, &flags);
		ft_putnbr(nb);
		if ((flags.num_before != 0) && (flags.num_before < flags.num_after))
			 ft_write_width(' ', flags.num_before, size);
	}
	return (size);
}*/


