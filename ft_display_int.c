/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:59:48 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/02 22:23:09 by ddecourt         ###   ########.fr       */
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

int				ft_handle_prec(int size, int nb, t_flags *flags)
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
		{
			if (nb < 0)
				size--;
			ft_write_width('0', flags->num_after, size);
		}
	}
	return(0);
}

int				ft_handle_width(int size, t_flags *flags)
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
}


int				ft_display_int(int n, t_flags flags)
{
	long int nb;
	int			size;

	nb = (long int)n;
	size = ft_get_size(nb);

	if ((flags.num_before == 0) && (flags.num_after == 0))
	{
		if (nb < 0)
			ft_putchar('-');
		ft_putnbr(nb);
	}
	if ((flags.num_before != 0) && (flags.num_after == 0))
	{
		if ((nb < 0) && (flags.zero == 1))
			ft_putchar('-');
		if (flags.minus == 0)
			ft_handle_prec(size, nb, &flags);
		if ((nb < 0) && (flags.zero == 0))
			ft_putchar('-');
		ft_putnbr(nb);
		if (flags.minus == 1)
			ft_handle_prec(size, nb, &flags);
	}
	if ((flags.num_before == 0) && (flags.num_after != 0))
	{
		if (nb < 0)
		{
			ft_putchar('-');
			size--;
		}
		ft_handle_width(size, &flags);
		ft_putnbr(nb);
	}
	if ((flags.num_before != 0) && (flags.num_after != 0))
	{
		if ((flags.minus == 1) || ((flags.num_after > flags.num_before) && (nb < 0)))
		{
			if (nb < 0)
			{
				ft_putchar('-');
			}
			ft_handle_width(size, &flags);
			if (flags.num_after > flags.num_before)
				ft_handle_prec(size, nb, &flags);
			ft_putnbr(nb);
			if (flags.num_after < flags.num_before)
				ft_handle_prec(size, nb, &flags);
			return (0);
		}
		if (flags.minus == 0)
		{	
			ft_handle_prec(size, nb, &flags);
			if (flags.num_after > flags.num_before)
				ft_handle_width(size, &flags);
			if (nb < 0)
				ft_putchar('-');
			if (flags.num_after < flags.num_before)
				ft_handle_width(size, &flags);
			ft_putnbr(nb);
		}
	}
	return(0);
}
