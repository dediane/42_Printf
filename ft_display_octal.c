/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:00:31 by ddecourt          #+#    #+#             */
/*   Updated: 2020/12/25 16:53:03 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

size_t		ft_display_octal(int n)
{
	char	*res;
	size_t	size;

	res = ft_convert(n, "01234567");
	size = ft_strlen(res);
	ft_putstr(res);
	free(res);
	return (1 + size);
}
