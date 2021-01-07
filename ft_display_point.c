/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:52:17 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/07 17:49:00 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdio.h>

void	ft_display_point(void *n)
{
	char *res;

//	if ((int)n < 0)
//		n *= -1;
	printf("int de tmp: %i\n", (int)n);
	printf("hexa de tmp: %x\n",(int)n);
	printf("adresse du pointeur: %p\n", n);
	res = ft_convert((int)n, "0123456789abcdef");
	ft_putstr(res);
	free(res);
	return;
}
