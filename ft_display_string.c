/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:54:56 by ddecourt          #+#    #+#             */
/*   Updated: 2021/02/04 23:28:26 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_display_string(const char *s, t_flags *flags)
{
	int size;
	int i;

	i = 0;
	size = ft_strlen(s);
	if ((flags->num_after == 0) && (flags->minus == 0) && (size > flags->num_before))
	{
		size = ft_strlen(s);
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
	if ((flags->num_after == 0) && (flags->minus == 0) && (size < flags->num_before))
	{
		while (i < (flags->num_before - size))
		{
			ft_putchar(' ');
			i++;
		}
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
		size = flags->num_before;
	}

	if ((flags->num_after != 0) && (flags->dot == 1))
	{	
		while (s[i] && i < flags->num_after)
		{
			ft_putchar(s[i]);
			i++;
		}
		size = i;
	}
	if ((flags->num_before != 0) && (flags->minus == 1))
	{
		while (s[i] && i < flags->num_before)
		{
			ft_putchar(s[i]);
			i++;
		}
		while (i < flags->num_before)
		{
			ft_putchar(' ');
			i++;
		}
		size = i;
	}
	return (size);
}
