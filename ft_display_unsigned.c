/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:59:07 by ddecourt          #+#    #+#             */
/*   Updated: 2021/03/13 22:08:15 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_display_unsigned(int n, t_flags flags)
{
	int size;
	long int nb;

	nb = (long int)n;
	size = ft_display_int(nb, flags);
	return (size);
}
