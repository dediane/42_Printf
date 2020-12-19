/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 21:46:37 by ddecourt          #+#    #+#             */
/*   Updated: 2020/12/17 23:56:03 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_size(long int n)
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
		n = n / 16;
		size++;
	}
	if (size == 0)
		return (1);
	return (size);
}

char		*ft_convert_to_hexa(int n)
{
	long int	nb;
	int			size;
	char		*num;
	char		*hexa;

	hexa = "0123456789ABCDEF";
	nb = (long int)n;
	size = get_size(nb);
	if (!(num = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (nb < 0)
		nb *= -1;
	num[size] = '\0';
	while (size > 0)
	{
		num[--size] = (hexa[nb % 16]);
		nb = nb / 16;
	}
	if (n < 0)
		num[size] = '-';
	return (num);
}
