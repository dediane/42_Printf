/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printftest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:24:57 by ddecourt          #+#    #+#             */
/*   Updated: 2020/12/25 00:06:35 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	ft_printf(const char *format, ...)
{
	va_list args;
	int written;
	int value;
	const char *string;
	char current;

	written = 0;
	va_start(args, format);
	while(*format != '\0')
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
			if (current == 's')
			{
				string = (const char *)va_arg(args, const char *);
				written += ft_display_string(string);
			}
			else
			{
				value = (int)va_arg(args, int);
				if (current == 'd' || current == 'i')
					written += ft_display_int(value);
				if (current == 'u')
					written += ft_display_unsigned(value);
				if (current == 'c')
					written += ft_display_char((char)value);
				if (current == '%')
					written += ft_display_percent();
			}
		}
	}	
	va_end (args);
	return;
}

int main(void)
{
	/*ft_printf("Hello mon nom est %s.", "Diane c'est moi");
	ft_printf("Salut %d", 12896243);
	ft_printf("Bonjour %i", 292942);
	printf("Hello mon nom est %s", "Diane");
	printf("Salut %d", 785453);*/
	ft_printf("Mon prénom c'est: %s, j'ai %d ans et il fait %d je voudrais dire %s à tous le monde","Diane", 27, -234, "Bonjour");
}
