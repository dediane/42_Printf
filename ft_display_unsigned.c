/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:59:07 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/03 21:59:41 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_display_unsigned(int n, t_flags flags)
{
	long int nb;

	nb = (long int)n;
	ft_display_int(nb, flags);
	return (0);
}
