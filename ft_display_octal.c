/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:00:31 by ddecourt          #+#    #+#             */
/*   Updated: 2020/12/25 00:01:23 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_display_octal(int n)
{
	char	*res;
	size_t	size;

	res = ft_convert(n, "01");
	size = ft_strlen(res);
	return (1 + size);
}
