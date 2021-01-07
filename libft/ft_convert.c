/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 21:46:37 by ddecourt          #+#    #+#             */
/*   Updated: 2021/01/07 17:48:53 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_size(long int n, int len)
{
	int			size;

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

char			*ft_convert(int n, char *base)
{
	long int	nb;
	int			size;
	int			len;
	char		*num;

	nb = (long int)n;
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
