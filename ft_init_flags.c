/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:56:34 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/09 23:56:12 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags		ft_init_flags(t_flags flags)
{
	flags.minus = 0;
	flags.num_after = 0;
	flags.num_before = 0;
	flags.star = 0;
	flags.zero = 0;
	flags.dot = 0;
	return (flags);
}
