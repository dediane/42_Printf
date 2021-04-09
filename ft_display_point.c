/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:52:17 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/10 01:08:06 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_display_point(void *n, t_flags flags)
{
	char *res;
	int size;
	int i;

	res = NULL;
	size = 0;

	if (n == NULL)
	{
		if ((flags.num_before == 0) && (flags.num_after == 0))
		{
			if (flags.dot == 0)
			{
				ft_putstr("0x0");
				return(0);
			}
			ft_putstr("0x");
			return(0);
		}
		if ((flags.num_before != 0) && (flags.num_after == 0))
		{
			if (flags.dot == 0)
			{
				if (!(res = malloc(sizeof(char) * 4)))
					return (0);
				res = ft_strdup("0x0");
				size = 3;
			}
			if (flags.dot == 1)
			{
				if (!(res = malloc(sizeof(char) * 3)))
					return (0);
				res = ft_strdup("0x");
				size = 2;
			}
		}
	}
	if (n != NULL)
	{
		res = ft_convert((unsigned long)n, "0123456789abcdef");
		size = ft_strlen(res);
	}
	if ((flags.num_before != 0))
	{
		if (flags.num_after == 0)
		{
			i = 0;
			while( i < (flags.num_before - size))
			{
				ft_putchar(' ');
				i++;
			}
			ft_putstr(res);
		}
		if (flags.num_after != 0)
		{
			if (flags.num_after < flags.num_before)
			{
				i = 0;
				while(i < (flags.num_before - (flags.num_after + size)))
				{
					ft_putchar(' ');
					i++;
				}
				while(i < size)
				{
					ft_putchar('0');
					i++;
				}
				ft_putstr("0x");
				ft_putstr(res);
			}
			if (flags.num_after > flags.num_before)
			{
				i = 0;
				ft_putstr("0x");
				while (i < (flags.num_after - size))
				{
					ft_putchar('0');
					i++;
				}
				ft_putstr(res);
			}
		}
	}
	else
	{
		ft_putstr(res);
	}
	free(res);
	return (size);
}
