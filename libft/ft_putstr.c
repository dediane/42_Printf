/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:38:15 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/02 13:56:50 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_putstr(const char *s)
{
	unsigned int i;

	i = 0;
	while (i < ft_strlen(s))
	{
		ft_putchar(s[i]);
		i++;
	}		
}
