/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:56:13 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/19 21:37:54 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_display_char(char c, t_flags flags)
{
	if (flags.minus == 1)
		ft_putchar('-');
	ft_putchar(c);
	return;
}
