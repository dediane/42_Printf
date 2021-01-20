/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:59:48 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/20 20:54:27 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_display_int(int n, t_flags flags)
{
	int written;
	written = 0;
	if (flags.plus == 1)
	{
		ft_putchar('+');
		written++;
		flags.plus = 0;
	}
	if (n < 0)
	{
		ft_putchar('-');
		written++;
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		written++;
		return (written);
	}
	ft_display_int(n / 10, flags);;
	ft_putchar(n % 10 + '0');
	written++;
	return (written);
}
