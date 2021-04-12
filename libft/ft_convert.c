/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 21:46:37 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/12 15:32:44 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int		get_size(long unsigned int n, int len)
{
	int		size;

	size = 0;
	while (n > 0)
	{
		n = n / len;
		size++;
	}
	if (size == 0)
		return (1);
	return (size);
}

char			*ft_convert(unsigned long int n, char *base)
{
	unsigned long int	nb;
	int		size;
	int		len;
	char	*num;

	nb = n;
	len = ft_strlen(base);
	size = get_size(nb, len);
	if (!(num = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (nb < 0)
		nb *= -1;
	num[size] = '\0';
	while (size > 0)
	{
		num[--size] = (base[nb % len]);
		nb = nb / len;
	}
	return (num);
}
