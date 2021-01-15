/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:30:11 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/15 15:30:08 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef	struct	s_struct
{
	int	minus;
	int plus;
	int	zero;
	int	width;
	int	prec;
	int	dot;
}				t_flags;

void		ft_display_string(const char *s);
void		ft_display_char(char c);
void		ft_display_int(int n);
void		ft_display_unsigned(int n);
void		ft_display_octal(int n);
void		ft_display_hexa(unsigned int n);
void		ft_display_percent(void);
void		ft_display_point(void *n);
void		ft_printf(const char *format, ...);
void		ft_checkflag(char current, t_flags *flags);
t_flags		ft_init_flags(t_flags flags);

#endif
