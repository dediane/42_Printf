/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_big_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:46:57 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/09 22:49:02 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_display_big_hexa(unsigned int n, t_flags flags)
{
	char	*res;
	int		size;

	if (ft_check_exceptions_zero(n, flags) == 1)
		return (0);
	res = ft_convert(n, "0123456789ABCDEF");
	size = ft_strlen(res);
	if (flags.minus == 0)
	{
		ft_handle_prec_hexa(size, &flags);
		ft_handle_width_hexa(size, &flags);
		ft_putstr(res);
	}
	if (flags.minus == 1)
	{
		ft_handle_width_hexa(size, &flags);
		if (flags.num_after > flags.num_before)
			ft_handle_prec_hexa(size, &flags);
		ft_putstr(res);
		if (flags.num_after < flags.num_before)
			ft_handle_prec_hexa(size, &flags);
	}
	free(res);
	return (0);
}
