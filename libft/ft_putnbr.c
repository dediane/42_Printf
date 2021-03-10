/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 00:44:27 by ddecourt          #+#    #+#             */
/*   Updated: 2021/03/10 13:04:23 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_putnbr(int n, t_flags *flags)
{
	long int nb;

	nb = (long int)n;
	if (nb < 0)
	{
		if (flags->num_after == 0 && flags->num_before == 0)
			ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, flags);
		ft_putchar(nb % 10 + '0');
	}
	if (nb < 10)
	{
		ft_putchar(nb % 10 + '0');
	}
}
