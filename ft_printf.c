/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:59:36 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/29 00:09:10 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void			ft_parsing(char current, va_list args, t_flags flags, int *written)
{
	if (current == 's')
		*written += ft_display_string(va_arg(args, const char *));
	else
	{
		if (current == 'd' || current == 'i')
			*written += ft_display_int(va_arg(args, int), flags);
		if (current == 'c')
			ft_display_char((char)(va_arg(args, int)), flags);
		if (current == 'u')
			ft_display_unsigned(va_arg(args, int));
		if (current == 'o')
			ft_display_octal(va_arg(args, int));
		if (current == 'x')
			*written += ft_display_hexa(va_arg(args, unsigned int), flags);
		if (current == 'X')
			ft_display_big_hexa(va_arg(args, unsigned int), flags);
		if (current == 'p')
			ft_display_point(va_arg(args, void *));
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	int		written;
	char		current;
	t_flags		flags;

	written = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		current = *format;
		format++;
		flags = ft_init_flags(flags);
		if (current == '%')
		{
			current = *format++;
			while (!ft_strchr("cspdiouxX", current))
			{
				ft_checkflag(current, &flags);
				current = *format++;
				written++;
			}
			ft_parsing(current, args, flags, &written);
		}
		else
		{
			ft_putchar(current);
			current++;
			written++;
		}
	}
	va_end(args);
	return (written);
}
