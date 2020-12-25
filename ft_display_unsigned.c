/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:59:07 by ddecourt          #+#    #+#             */
/*   Updated: 2020/12/25 14:41:35 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

size_t		ft_display_unsigned(int n)
{
	size_t size;

	if (n < 10)
	{
		ft_putchar(n + '0');
		return (1);
	}
	size = ft_display_unsigned(n / 10);
	ft_putchar(n % 10 + '0');
	return (1 + size);
}

