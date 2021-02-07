/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:58:07 by ddecourt          #+#    #+#             */
/*   Updated: 2021/02/06 22:05:40 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_display_percent(t_flags flags)
{
	int size;
	int i;

	size = 1;
	i = 0;
	if ((flags.num_before != 0) && (flags.minus == 0) && (flags.zero == 0))
	{
		size = flags.num_before;
		while (i < size - 1)
		{
			ft_putchar(' ');
			i++;
		}
	}
	if ((flags.num_before != 0) && (flags.minus == 0) && (flags.zero == 1))
	{
		size = flags.num_before;
		while (i < size - 1)
		{
			ft_putchar('0');
			i++;
		}
	}

	ft_putchar('%');
	if ((flags.num_before != 0) && (flags.minus == 1))
	{
		size = flags.num_before;
		while (i < size - 1)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (size);
}
