/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:59:36 by ddecourt          #+#    #+#             */
/*   Updated: 2020/12/25 17:12:46 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void			ft_parsing(char current, int *written, va_list args)
{
	int			value;
	const char	*s;

	if (current == 's')
	{
		s = (const char *)va_arg(args, const char *);
		*written += ft_display_string(s);
	}
	else
	{
		value = (int)va_arg(args, int);
		if (current == 'd' || current == 'i')
			*written += ft_display_int(value);
		if (current == 'c')
			*written += ft_display_char((char)value);
		if (current == 'u')
			*written += ft_display_unsigned(value);
		if (current == 'o')
			*written += ft_display_octal(value);
		if (current == 'x' || current == 'X')
			*written += ft_display_hexa(value);
	}
}

void			ft_printf(const char *format, ...)
{
	va_list		args;
	int			written;
	char		current;

	written = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		current = *format;
		format++;
		if (current != '%')
		{
			write(1, &current, 1);
			current++;
			continue;
		}
		else
		{
			current = *format++;
			ft_parsing(current, &written, args);
		}
	}
	va_end(args);
	return ;
}
