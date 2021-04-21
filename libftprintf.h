/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:30:11 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/21 14:00:22 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct		s_struct
{
	int		minus;
	int		num_after;
	int		num_before;
	int		star;
	int		zero;
	int		dot;
}					t_flags;

int			ft_display_string(const char *s, t_flags flags);
int			ft_display_char(char c, t_flags flags);
int			ft_display_int(int n, t_flags flags);
int			ft_display_unsigned(unsigned int n, t_flags flags);
int			ft_display_hexa(unsigned long int n, t_flags flags);
int			ft_display_big_hexa(unsigned int n, t_flags flags);
int			ft_display_percent(t_flags flags);
int			ft_display_point(void *n, t_flags flags);
int			ft_printf(const char *format, ...);
int			ft_write_width(char c, int max, int size);
int			get_num(int i);
int			ft_get_size(long int n);
int			ft_get_size_u(unsigned int n);
int			ft_handle_width_u(int size, t_flags *flags);
int			ft_display_prec_width_x(char *res, int size, t_flags flags);
t_flags		ft_init_flags(t_flags flags);
char		*ft_convert(unsigned long int n, char *base);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_handle_width(int size, int nb, t_flags flags);
void		ft_handle_width2(int size, int nb, t_flags flags);
void		ft_checkflag(char current, t_flags *flags, va_list args);
void		ft_putchar(char c);
void		ft_putnchr(const char *s, int n);
void		ft_putstr(const char *s);
void		ft_putnbr(int n);
void		ft_putnbr_u(unsigned int n);
void		ft_handle_prec_u(int size, t_flags *flags);
void		ft_display_prec_x(char *res, int size, t_flags flags);
void		ft_handle_prec(int size, int nb, t_flags flags);
void		ft_prec_func(int size, int nb, t_flags flags);
void		ft_prec_func2(int nb, t_flags flags);
size_t		ft_strlen(const char *s);
unsigned int	ft_check_exceptions_zero(unsigned int nb, t_flags flags);

#endif
