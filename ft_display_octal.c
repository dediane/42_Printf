/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:00:31 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/18 23:34:51 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_display_octal(int n)
{
	char	*res;

	res = ft_convert(n, "01234567");
	ft_putstr(res);
	free(res);
	return;
}
