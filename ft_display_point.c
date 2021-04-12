/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:52:17 by ddecourt          #+#    #+#             */
/*   Updated: 2021/04/11 19:38:11 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_handle_n_null(void *n, t_flags flags)
{
	if (n == NULL)
	{		
		if ((flags.num_before == 0) && (flags.num_after == 0))
		{
			if (flags.dot == 0)
			{
				ft_putstr("0x0");
				return(1);
			}
			ft_putstr("0x");
			return(1);
		}
		if ((flags.num_before != 0))
		{
			if (flags.dot == 0)
			{
				ft_handle_prec_hexa(3, &flags);
				ft_putstr("0x0");
			}
			if (flags.dot == 1)
			{
				ft_handle_prec_hexa(2, &flags);
				ft_putstr("0x");
			}
		}
		return(1);
	}
	if (n == 0)
	{
		if (flags.num_before == 0)
		{
			ft_putstr("0x");
			if (flags.num_after != 0)
				ft_write_width('0', flags.num_after, 0);
			return (1);
		}
		if (flags.num_before != 0)
		{
			ft_handle_prec_hexa(3, &flags);
			ft_putstr("0x0");
		}
		return (1);
	}
	return (0);
}

int	ft_display_point(void *n, t_flags flags)
{
	char *res;
	int size;

	if (ft_handle_n_null(n, flags) == 1)
		return (0);
	res = ft_convert((unsigned long int)n, "0123456789abcdef");
	size = (int)(ft_strlen(res));
	size += 2;
	if (flags.minus == 0)
	{
		if (flags.num_after > flags.num_before)
		{
			ft_putstr("0x");
			size-= 2;
		}
       		ft_handle_prec_hexa(size, &flags);
		ft_handle_width_hexa(size, &flags);
		if (!(flags.num_after > flags.num_before))
			ft_putstr("0x");
		ft_putstr(res);
	}
	if (flags.minus== 1)
	{
		ft_handle_width_hexa(size, &flags);
		if (flags.num_after > flags.num_before)
			ft_handle_prec_hexa(size, &flags);
		ft_putstr("0x");
		ft_putstr(res);
		if (flags.num_after < flags.num_before)
			ft_handle_prec_hexa(size, &flags);
	}
	free(res);
	return (0);
}
	/*char *res;
	int size;
	int i;

	res = NULL;;
	size = 0;

	if (n == NULL)
	{
		if ((flags.num_before == 0) && (flags.num_after == 0))
		{
			if (flags.dot == 0)
			{
				ft_putstr("0x0");
				return(0);
			}
			ft_putstr("0x");
			return(0);
		}
		if ((flags.num_before != 0) && (flags.num_after == 0))
		{
			if (flags.dot == 0)
			{
				if (!(res = malloc(sizeof(char) * 4)))
					return (0);
				res = ft_strdup("0x0");
				size = 3;
			}
			if (flags.dot == 1)
			{
				if (!(res = malloc(sizeof(char) * 3)))
					return (0);
				res = ft_strdup("0x");
				size = 2;
			}
		}
	}
	if ((n != NULL) && (n != 0))
	{
		res = ft_convert((unsigned long int)n, "0123456789abcdef");
		size = ft_strlen(res);
	}
	if ((flags.num_before != 0))
	{
		if (flags.num_after == 0)
		{
			i = 0;
			while( i < (flags.num_before - size))
			{
				ft_putchar(' ');
				i++;
			}
			if (n != NULL)
			{
				ft_putstr("0x");
				ft_putstr(res);
			}
			if (n == NULL)
				ft_putstr(res);
		}
		if (flags.num_after != 0)
		{
			if (flags.num_after < flags.num_before)
			{
				i = 0;
				while(i < (flags.num_before - (flags.num_after + size)))
				{
					ft_putchar(' ');
					i++;
				}
				while(i < size)
				{
					ft_putchar('0');
					i++;
				}
				if (n != NULL)
				{
					ft_putstr("0x");
					ft_putstr(res);
				}
			}
			if (flags.num_after > flags.num_before)
			{
				i = 0;
				ft_putstr("0x");
				while (i < (flags.num_after - size))
				{
					ft_putchar('0');
					i++;
				}
				if (n != NULL)
					ft_putstr(res);
			}
		}
	}
	free(res);
	return (size);
}*/
