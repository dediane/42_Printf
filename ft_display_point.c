/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:52:17 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/14 14:53:20 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_handle_n_null(void *n, t_flags flags)
{
	if (n == NULL)
	{		
		if ((flags.num_before == 0) && (flags.num_after == 0))
		{
			if (flags.dot == 0)
			{
				ft_putstr("0x0");
				return(1);
			}
			ft_putstr("0x");
			return(1);
		}
		if ((flags.num_before != 0))
		{
			if (flags.dot == 0)
			{
				ft_handle_prec_u(3, &flags);
				ft_putstr("0x0");
			}
			if (flags.dot == 1)
			{
				ft_handle_prec_u(2, &flags);
				ft_putstr("0x");
			}
		}
		return(1);
	}
	if (n == 0)
	{
		if (flags.num_before == 0)
		{
			ft_putstr("0x");
			if (flags.num_after != 0)
				ft_write_width('0', flags.num_after, 0);
			return (1);
		}
		if (flags.num_before != 0)
		{
			ft_handle_prec_u(3, &flags);
			ft_putstr("0x0");
			return (1);
		}
	}
	return (0);
}

int	ft_display_point(void *n, t_flags flags)
{
	char *res;
	int size;

	if (ft_handle_n_null(n, flags) == 1)
		return (0);
	res = ft_convert((unsigned long int)n, "0123456789abcdef");
	size = (int)(ft_strlen(res));
	size += 2;
	if (flags.minus == 0)
	{
		if (flags.num_after > flags.num_before)
		{
			ft_putstr("0x");
			size-= 2;
		}
       		ft_handle_prec_u(size, &flags);
		ft_handle_width_u(size, &flags);
		if (!(flags.num_after > flags.num_before))
			ft_putstr("0x");
		ft_putstr(res);
	}
	if (flags.minus== 1)
	{
		ft_handle_width_u(size, &flags);
		if (flags.num_after > flags.num_before)
			ft_handle_prec_u(size, &flags);
		ft_putstr("0x");
		ft_putstr(res);
		if (flags.num_after < flags.num_before)
			ft_handle_prec_u(size, &flags);
	}
	free(res);
	return (0);
}
