/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:59:48 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/29 01:27:48 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_get_size(long int n)
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
		n = n /10;
		size++;
	}
	size++;
	return (size);
}

int		ft_display_int(int n, t_flags flags)
{
	long int nb;
	int size;

	nb = (long int)n;
	size = ft_get_size(nb);
	if (flags.plus == 1)
	{
		ft_putchar('+');
		flags.plus = 0;
		size++;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_display_int(nb / 10, flags);
		ft_putchar(nb % 10 + '0');
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	return (size);
}
