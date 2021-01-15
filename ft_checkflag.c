/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:27:36 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/15 15:46:27 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void		ft_checkflag(char current, t_flags *flags)
{
	if (current == '-')
		flags->minus = 1;
	if (current == '+')
		flags->plus = 1;
	if (current == '0')
		flags->zero = 1;
	if (current == '.')

}
