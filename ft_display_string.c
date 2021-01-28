/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:54:56 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/29 00:08:00 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_display_string(const char *s)
{
	int size;

	size = ft_strlen(s);
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
	return (size);
}
