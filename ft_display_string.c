/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:54:56 by ddecourt          #+#    #+#             */
/*   Updated: 2021/02/02 22:25:32 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_display_string(const char *s, t_flags *flags)
{
	int size;
	int i;

	i = 0;
	if (flags->num_after == 0)
	{
		size = ft_strlen(s);
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
	if ((flags->num_after != 0) && (flags->dot == 1))
	{
		size = flags->num_after;
		while (s[i] && i < flags->num_after)
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	return (size);
}
