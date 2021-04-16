/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_big_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:46:57 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/16 15:15:57 by ddecourt         ###   ########.fr       */
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
	if ((flags.num_before == 0) && (flags.num_after == 0))
		ft_display_prec_x(res, size, flags);
	if ((flags.num_before != 0) && (flags.num_after == 0))
		ft_display_prec_x(res, size, flags);
	if ((flags.num_before == 0) && (flags.num_after != 0))
	{
		ft_handle_width_u(size, &flags);
		ft_putstr(res);
	}
	if ((flags.num_before != 0) && (flags.num_after != 0))
		ft_display_prec_width_x(res, size, flags);
	free(res);
	return (0);
}
