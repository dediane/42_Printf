/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_big_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:46:57 by ddecourt          #+#    #+#             */
/*   Updated: 2021/02/03 14:21:57 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_display_big_hexa(unsigned int n, t_flags flags)
{
	char	*res;
	int		size;

	if (flags.hash == 1 && n != 0)
		ft_putstr("0X");
	res = ft_convert(n, "0123456789ABCDEF");
	size = ft_strlen(res);
	size += ft_handle_flags_hexa(size, &flags);
	ft_putstr(res);
	free(res);
	return (size);
}
