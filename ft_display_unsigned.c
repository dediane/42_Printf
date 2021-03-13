/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:59:07 by ddecourt          #+#    #+#             */
/*   Updated: 2021/03/10 14:38:18 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	get_size(int n)
{	
	int size;

	size = 0;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

void		ft_put_unsigned(int n)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
		return;
	}
	ft_put_unsigned(n / 10);
	ft_putchar(n % 10 + '0');
}

int		ft_display_unsigned(int n, t_flags *flags)
{
	int size;
	long int nb;

	nb = (long int)n;
	size = get_size(nb);
	ft_put_unsigned(nb);
	return (size);
}
