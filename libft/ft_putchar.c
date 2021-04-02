/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 21:30:49 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/02 14:10:21 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

int		get_num(int i)
{
	static int	num = 0;
	int			swp;

	swp  = num;
	num += i;
	if (i == 0)
	{
		num = 0;
		return swp;
	}
	return swp;
}

void	ft_putchar(char c)
{
	get_num(1);
	write(1, &c, 1);
}
