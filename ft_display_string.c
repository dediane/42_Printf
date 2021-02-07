/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:54:56 by ddecourt          #+#    #+#             */
/*   Updated: 2021/02/07 22:53:25 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_display_string(const char *s, t_flags *flags)
{
	int size;
	int i;

	i = 0;
	size = ft_strlen(s);
	
	if (flags->dot == 0)
	{
		if (((flags->minus == 0) || (flags->minus == 1)) && (flags->num_before < size))
		{
			ft_putstr(s);
			return (size);
		}
		if ((flags->minus == 0) && (flags->num_before > size))
		{
			while (i < (flags->num_before - size))
			{
				ft_putchar(' ');
				i++;
			}
			ft_putstr(s);
			return (flags->num_before);
		}
		if ((flags->minus == 1) && (flags->num_before > size))
		{
			ft_putstr(s);
			while (i < (flags->num_before - size))
			{
				ft_putchar(' ');
				i++;
			}
			return (flags->num_before);
		}
	}
	if (flags->dot == 1)
	{	
		if ((flags->num_after == 0) && (flags->num_before == 0))
			return (0);
		if (flags->minus == 0)
		{
			if (flags->num_before < flags->num_after)
			{
				if (flags->num_after < size)
				{
					ft_putnchr(s, flags->num_after);
					return (flags->num_after);
				}
				else
					ft_putstr(s);
			}
			if (flags->num_before > flags->num_after)
			{
				if (flags->num_after < size)
				{
					while (i < (flags->num_before - flags->num_after))
					{
						ft_putchar(' ');
						i++;
					}
					ft_putnchr(s, flags->num_after);
					return (flags->num_before);
				}
				if (flags->num_after > size)
				{
					while (i < (flags->num_before - size))
					{
						ft_putchar(' ');
						i++;
					}
					ft_putstr(s);
					return (flags->num_before);
				}
			}
		}
		if (flags->minus == 1)
		{
			if (flags->num_before < flags->num_after)
			{
				if (flags->num_after < size)
				{
					ft_putnchr(s, flags->num_after);
					return (flags->num_after);
				}
				else
					ft_putstr(s);
			}
			if (flags->num_before > flags->num_after)
			{
				if (flags->num_after < size)
				{
					ft_putnchr(s, flags->num_after);
					while (i < (flags->num_before - flags->num_after))
					{
						ft_putchar(' ');
						i++;
					}
					return (flags->num_before);
				}
				if (flags->num_after > size)
				{
					ft_putstr(s);
					while (i < flags->num_before - size)
					{
						ft_putchar(' ');
						i++;
					}
					return (flags->num_before);
				}
			}
		}
	}

	return (size);
}
