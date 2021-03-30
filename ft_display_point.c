/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:52:17 by ddecourt          #+#    #+#             */
/*   Updated: 2021/03/21 11:23:26 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_display_point(void *n)
{
	char *res;
	int size;

	res = ft_convert((unsigned long int)n, "0123456789abcdef");
	ft_putstr(res);
	size = ft_strlen(res);
	free(res);
	return (size);
}
