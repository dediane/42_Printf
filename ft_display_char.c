/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:56:13 by ddecourt          #+#    #+#             */
/*   Updated: 2021/02/06 21:50:46 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_display_char(char c, t_flags flags)
{
	int	size;
	int	i;

	size = 1;
	i = 0;
	if (flags.num_before != 0)
	{
		size = flags.num_before;
		while (i < size - 1)
		{
			ft_putchar(' ');
			i++;
		}
	}
	ft_putchar(c);
	return (size);
}
