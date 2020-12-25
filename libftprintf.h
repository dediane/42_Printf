/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:30:11 by ddecourt          #+#    #+#             */
/*   Updated: 2020/12/25 14:27:54 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

size_t		ft_display_string(const char *s);
size_t		ft_display_char(char c);
size_t		ft_display_int(int n);
size_t		ft_display_unsigned(int n);
size_t		ft_display_octal(int n);
size_t		ft_display_hexa(int n);
size_t		ft_display_percent(void);
void		ft_printf(const char *format, ...);

#endif
