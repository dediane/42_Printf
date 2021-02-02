/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:30:11 by ddecourt          #+#    #+#             */
/*   Updated: 2021/02/02 21:46:12 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_struct
{
	int	minus;
	int	plus;
	int	num_after;
	int	num_before;
	int	hash;
	int	star;
	int	zero;
	int	width;
	int	prec;
	int	dot;
}				t_flags;

int		ft_display_string(const char *s, t_flags *flags);
int		ft_display_char(char c, t_flags flags);
int		ft_display_int(int n, t_flags flags);
void		ft_display_unsigned(int n);
void		ft_display_octal(int n);
int		ft_display_hexa(unsigned int n, t_flags flags);
int		ft_display_big_hexa(unsigned int n, t_flags flags);
int		ft_display_percent(void);
void		ft_display_point(void *n);
int		ft_printf(const char *format, ...);
void		ft_checkflag(char current, t_flags *flags);
t_flags		ft_init_flags(t_flags flags);
char		*ft_convert(unsigned int n, char *base);
char		*ft_strchr(const char *s, int c);
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_putnbr(int n, t_flags *flags);
size_t		ft_strlen(const char *s);

#endif
