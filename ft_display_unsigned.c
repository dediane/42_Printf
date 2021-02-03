/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:59:07 by ddecourt          #+#    #+#             */
/*   Updated: 2021/02/02 22:26:12 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_display_unsigned(int n)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_display_unsigned(n / 10);
	ft_putchar(n % 10 + '0');
	return ;
}
