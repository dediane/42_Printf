/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:59:36 by ddecourt          #+#    #+#             */
/*   Updated: 2020/12/27 23:12:02 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void			ft_parsing(char current, va_list args)
{
	if (current == 's')
		ft_display_string(va_arg(args, const char *));
	else
	{
		if (current == 'd' || current == 'i')
			ft_display_int(va_arg(args, int));
		if (current == 'c')
			ft_display_char((char)(va_arg(args, int)));
		if (current == 'u')
			ft_display_unsigned(va_arg(args, int));
		if (current == 'o')
			ft_display_octal(va_arg(args, int));
		if (current == 'x' || current == 'X')
			ft_display_hexa(va_arg(args, int));
	}
}

void			ft_printf(const char *format, ...)
{
	va_list		args;
	char		current;

	va_start(args, format);
	while (*format != '\0')
	{
		current = *format;
		format++;
		if (current == '%')
		{
			current = *format++;
			ft_parsing(current, args);
		}
		else
		{
			ft_putchar(current);
			current++;
		}
	}
	va_end(args);
	return ;
}
