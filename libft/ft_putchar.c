/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 21:30:49 by ddecourt          #+#    #+#             */
/*   Updated: 2021/03/31 13:53:53 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

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
