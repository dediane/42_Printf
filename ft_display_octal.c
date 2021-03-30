/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:00:31 by ddecourt          #+#    #+#             */
/*   Updated: 2021/03/21 11:19:52 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_display_octal(int n)
{
	char	*res;
	int	size;

	res = ft_convert(n, "01234567");
	ft_putstr(res);
	size = ft_strlen(res);
	free(res);
	return(size) ;
}
