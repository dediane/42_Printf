/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:01:35 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/19 23:15:21 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_display_hexa(unsigned int n, t_flags flags)
{
	char	*res;

	if (flags.hash == 1 && n != 0)
		ft_putstr("0x");
	res = ft_convert(n, "0123456789abcdef");
	ft_putstr(res);
	free(res);
	return;
}
