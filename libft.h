/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:31:32 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/13 14:03:39 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

void		ft_putchar(char c);
size_t		ft_strlen(char *s);
void		ft_putstr(char *s);
char		*ft_convert(unsigned int n, char *base);

#endif
