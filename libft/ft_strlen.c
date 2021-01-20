/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:19:09 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/20 21:09:16 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t size;

	size = 0;
	while (*s)
	{
		size++;
		s++;
	}
	return (size);
}
