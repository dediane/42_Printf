/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:56:34 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/29 18:30:03 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags		ft_init_flags(t_flags flags)
{
	flags.minus = 0;
	flags.plus = 0;
	flags.num_after = 0;
	flags.num_before = 0;
	flags.star = 0;
	flags.hash = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.prec = 0;
	flags.dot = 0;

	return(flags);
}
