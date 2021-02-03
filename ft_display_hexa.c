/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 00:01:35 by ddecourt          #+#    #+#             */
/*   Updated: 2021/02/03 14:13:17 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_handle_flags_hexa(int size, t_flags *flags)
{
	int			i;

	i = 0;
	if (flags->num_before != 0)
	{
		i = ft_write_width(' ', 0, flags->num_before, size);
	}
	else if (flags->num_after != 0)
	{
		while (i < (flags->num_before - size))
		{
			ft_putchar('0');
			i++;
		}
	}
	return (i);
}

int			ft_display_hexa(unsigned int n, t_flags flags)
{
	char	*res;
	int		size;

	if (flags.hash == 1 && n != 0)
		ft_putstr("0x");
	res = ft_convert(n, "0123456789abcdef");
	size = (int)(ft_strlen(res));
	size += ft_handle_flags_hexa(size, &flags);
	ft_putstr(res);
	free(res);
	return (size);
}
