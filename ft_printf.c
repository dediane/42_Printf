/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:24:57 by ddecourt          #+#    #+#             */
/*   Updated: 2020/12/24 01:01:13 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
    write(1, &c, 1);
}


size_t ft_display_int(int value)
{
    size_t size;
    if (value < 10)
    {
	ft_putchar(value + '0');
	return (1);
    }
    size = ft_display_int(value/10);
    ft_putchar(value % 10 + '0');
    return (1 + size);
}

size_t ft_display_string(const char *s)
{
    size_t size;

    while(*s)
    {
	ft_putchar(*s);
	s++;
	size++;
    }
    return (1 + size);
}

void	ft_printf(const char *format, ...)
{
    va_list args;
    int written;
    int value;
    const char *string;
    char current;

    written = 0;
    va_start(args, format);

    while ((current = *format) != '\0')
    {
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
	    if (current == 'd' || current == 'i')
	    {
		value = (int)va_arg(args, int);
		written += ft_display_int(value);
	    }
	    if (current == 's')
	    {
		string = (const char *)va_arg(args, const char *);
		written += ft_display_string(string);
	    }
	}
    }	
    va_end (args);

    return;
}

int main(int argc, char **argv)
{
    ft_printf("Hello mon nom est %s.", "Diane c'est moi");
    ft_printf("Salut %d", 12896243);
    ft_printf("Bonjour %i", 292942);
    printf("Hello mon nom est %s", "Diane");
    printf("Salut %d", 785453);
}
