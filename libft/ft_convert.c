/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 21:46:37 by ddecourt          #+#    #+#             */
/*   Updated: 2021/02/02 22:40:37 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int		get_size(unsigned int n, int len)
{
	int		size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n > 0)
	{
		n = n / len;
		size++;
	}
	if (size == 0)
		return (1);
	return (size);
}

char			*ft_convert(unsigned int n, char *base)
{
	unsigned int	nb;
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
	if (n < 0)
		num[size] = '-';
	return (num);
}
