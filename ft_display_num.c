/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:52:09 by ddecourt          #+#    #+#             */
/*   Updated: 2020/12/24 23:46:35 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_display_int(int n)
{
	size_t	size;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		return (1);
	}
	size = ft_display_int(n / 10);
	ft_putchar(n % 10 + '0');
	return (1 + size);
}

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

size_t		ft_display_octal(int n)
{
	char	*res;
	size_t	size;

	res = ft_convert(n, "01");
	size = ft_strlen(res);
	return (1 + size);
}

size_t		ft_display_hexa(int n)
{
	char	*res;
	size_t	size;

	res = ft_convert(n, "0123456789ABCDEF");
	size = ft_strlen(res);
	return (1 + size);
}
