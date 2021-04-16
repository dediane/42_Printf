/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:01:35 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/16 15:17:38 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_display_prec_width_x(char *res, int size, t_flags flags)
{
	if (flags.minus == 1)
	{
		if (!(flags.num_after > flags.num_before))
			ft_handle_width_u(size, &flags);
		if (flags.num_after > flags.num_before)
			ft_handle_prec_u(size, &flags);
		ft_putstr(res);
		if (flags.num_after < flags.num_before)
			ft_handle_prec_u(size, &flags);
		return (0);
	}
	if (flags.minus == 0)
	{
		ft_handle_prec_u(size, &flags);
		if (flags.num_after < flags.num_before)
			ft_handle_width_u(size, &flags);
		ft_putstr(res);
	}
	return (0);
}

void			ft_display_prec_x(char *res, int size, t_flags flags)
{
	if ((flags.num_before == 0) && (flags.num_after == 0))
		ft_putstr(res);
	if ((flags.num_before != 0) && (flags.num_after == 0))
	{
		if (flags.minus == 0)
			ft_handle_prec_u(size, &flags);
		ft_putstr(res);
		if (flags.minus == 1)
			ft_handle_prec_u(size, &flags);
	}
}

int				ft_display_hexa(unsigned long int n, t_flags flags)
{
	char		*res;
	int			size;

	if (ft_check_exceptions_zero(n, flags) == 1)
		return (0);
	res = ft_convert(n, "0123456789abcdef");
	size = (int)(ft_strlen(res));
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
