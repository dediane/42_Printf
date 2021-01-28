/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:01:35 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/29 00:10:30 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_display_hexa(unsigned int n, t_flags flags)
{
	char	*res;
	int	size;

	if (flags.hash == 1 && n != 0)
		ft_putstr("0x");
	res = ft_convert(n, "0123456789abcdef");
	ft_putstr(res);
	size = (int)(ft_strlen(res));
	free(res);
	return(size);
}
