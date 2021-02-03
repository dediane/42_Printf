/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:56:13 by ddecourt          #+#    #+#             */
/*   Updated: 2021/02/02 22:05:19 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_display_char(char c, t_flags flags)
{
	int	size;

	size = 0;
	if (flags.minus == 1)
	{
		ft_putchar('-');
		size++;
	}
	ft_putchar(c);
	size++;
	return (size);
}
