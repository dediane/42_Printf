/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:47:14 by ddecourt          #+#    #+#             */
/*   Updated: 2020/12/25 15:55:24 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
