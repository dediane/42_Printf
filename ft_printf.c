/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:24:57 by ddecourt          #+#    #+#             */
/*   Updated: 2020/12/25 01:50:46 by ddecourt         ###   ########.fr       */
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



static int		get_size(long int n, int len)
{
	int			size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n > 0)
	{
		n = n / len;
		size++;
	}
	if (size == 0)
		return (1);
	return (size);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

size_t			ft_convert(int n, char *base)
{
	long int	nb;
	int			size;
	int			len;
	char		*num;

	nb = (long int)n;
	len = ft_strlen(base);
	size = get_size(nb, len);
	if (!(num = malloc(sizeof(char) * (size + 1))))
		return (0);
	if (nb < 0)
		nb *= -1;
	num[size] = '\0';
	while (size > 0)
	{
		num[--size] = (base[nb % len]);
		nb = nb / len;
	}
	if (n < 0)
		num[size] = '-';
	ft_putstr(num);
	return (1 + size);
}

size_t		ft_display_int(int n)
{
	size_t	size;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		return (1);
	}
	size = ft_display_int(n / 10);
	ft_putchar(n % 10 + '0');
	return (1 + size);
}

size_t		ft_display_unsigned(int n)
{
	size_t	size;

	if (n < 10)
	{
		ft_putchar(n + '0');
		return (1);
	}
	size = ft_display_unsigned(n / 10);
	ft_putchar(n % 10 + '0');
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

size_t		ft_display_char(char c)
{
	ft_putchar(c);
	return (1);
}

size_t		ft_display_percent(void)
{
	ft_putchar('%');
	return (1);
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
			if (current == 'u')
			{
				value = (int)va_arg(args, int);
				written += ft_display_unsigned(value);
			}
			if (current == 'c')
			{
				value = (int)va_arg(args, int);
				written += ft_display_char((char)value);
			}
			if (current == '%')
				written += ft_display_percent();
			if (current == 'x' || current == 'X')
			{
				value =(int)va_arg(args, int);
				written += ft_convert(value, "0123456789ABCDEF");
			}
			if (current == 'o')
			{
				value =(int)va_arg(args, int);
				written += ft_convert(value, "01234567");
			}
		}
	}	
	va_end (args);
	return;
}

int main(int argc, char **argv)
{
	/*ft_printf("Hello mon nom est %s.", "Diane c'est moi");
	ft_printf("Salut %d", 12896243);
	ft_printf("Bonjour %i", 292942);
	printf("Hello mon nom est %s", "Diane");
	printf("Salut %d", 785453);*/
	ft_printf("Mon prénom c'est: %s, j'ai %d ans et il fait %d je voudrais dire %s à tous le monde. --- Voici le chiffre 42 en octal: %o, et en hexa: %x autre Hexa: %X","Diane", 27, -234, "Bonjour", 42, 42, 42);
}
