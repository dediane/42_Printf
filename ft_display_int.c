/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:59:48 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/30 13:18:48 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_get_size(long int n)
{
	int size;

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

int	ft_handle_flags(int size, t_flags *flags)
{
	int i;

	i = 0;
	if (flags->num_before != 0)
	{
		if(flags->zero == 1)
		{
			while (i < (flags->num_before - size))
			{
				ft_putchar('0');
				i++;
			}
		}
		if(flags->zero == 0)
		{
			while (i < (flags->num_before - size))
			{
				ft_putchar(' ');
				i++;
			}
		}
	}
	return (i);
}

int		ft_display_int(int n, t_flags flags)
{
	long int	nb;
	int			size;

	nb = (long int)n;
	size = ft_get_size(nb);
	if (flags.plus == 1)
	{
		ft_putchar('+');
		flags.plus = 0;
		size++;
	}
	size += ft_handle_flags(size, &flags);
	ft_putnbr(n);
	return (size);
}
