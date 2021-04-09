/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:30:11 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/09 21:48:57 by ddecourt         ###   ########.fr       */
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

int		ft_display_string(const char *s, t_flags flags);
int		ft_display_char(char c, t_flags flags);
int		ft_display_int(int n, t_flags flags);
int		ft_display_unsigned(unsigned int n, t_flags flags);
int		ft_display_octal(int n);
int		ft_display_hexa(unsigned int n, t_flags flags);
int		ft_display_big_hexa(unsigned int n, t_flags flags);
int		ft_display_percent(t_flags flags);
int		ft_display_point(void *n, t_flags flags);
int		ft_printf(const char *format, ...);
void		ft_checkflag(char current, t_flags *flags, va_list args);
t_flags		ft_init_flags(t_flags flags);
int				ft_write_width(char c, int max, int size);
int				ft_handle_flags_hexa(int size, t_flags *flags);
char		*ft_convert(unsigned long int n, char *base);
char		*ft_strchr(const char *s, int c);
void		ft_putchar(char c);
void		ft_putnchr(const char *s, int n);
void		ft_putstr(const char *s);
void		ft_putnbr(int n);
size_t		ft_strlen(const char *s);
char 		*ft_strdup(const char *s1);
int		get_num(int i);
int		ft_handle_prec_hexa(int size, t_flags *flags);
int		ft_handle_width_hexa(int size, t_flags *flags);
int		ft_handle_width(int size, int nb, t_flags *flags);
int		ft_check_exceptions_zero(int nb, t_flags flags);
int		ft_get_size(long int n);
int		ft_write_width(char c, int max, int size);

#endif
