/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:52:17 by ddecourt          #+#    #+#             */
/*   Updated: 2021/02/02 22:24:34 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_display_point(void *n)
{
	char *res;

	res = ft_convert((unsigned long int)n, "0123456789abcdef");
	ft_putstr(res);
	free(res);
	return ;
}
