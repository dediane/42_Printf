/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:27:36 by ddecourt          #+#    #+#             */
/*   Updated: 2021/03/31 13:24:32 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_checkflag(char current, t_flags *flags, va_list args)
{
	if (current == '-')
		flags->minus = 1;
	if (current == '+')
		flags->plus = 1;
	if (current == '*')
		flags->star = va_arg(args, int);
	if (current == '#')
		flags->hash = 1;
	if ((current == '0') && (flags->num_before == 0) && (flags->num_after == 0))
		flags->zero = 1;
	if  ((current == '0') && (flags->dot == 1) && (flags->num_after != 0))
		flags->num_after = (flags->num_after * 10) + (int)current - 48;
	if  ((current == '0') && (flags->dot == 0) && (flags->num_before != 0))
		flags->num_before = (flags->num_before * 10) + (int)current - 48;
	if (current == '.')
		flags->dot = 1;
	if ((current > '0' && current <= '9') && (flags->dot == 1)) 
		flags->num_after = (flags->num_after * 10) + (int)current - 48;
	if ((current > '0' && current <= '9') && (flags->dot == 0))
		flags->num_before = (flags->num_before * 10) + (int)current - 48;
}
