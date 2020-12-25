/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:59:27 by ddecourt          #+#    #+#             */
/*   Updated: 2020/12/24 23:50:01 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_display_string(const char *s)
{
	size_t	size;
	size = 0;

	while (*s)
	{
		ft_putchar(*s);
		s++;
		size++;
	}
	return (1 + size);
}

size_t		ft_display_char(char c)
{
	ft_putchar(c);
	return (1);
}

size_t		ft_display_purcent(void)
{
	ft_putchar('%');
	return (1);
}
