/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:24:57 by ddecourt          #+#    #+#             */
/*   Updated: 2020/12/23 12:28:37 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_printf(const char *format, ...)
{
    va_list args;
    int done;

    va_start (args, format);
    done = ft_vfprintf(stdout, format, args);
    va_end (args);

    return(done);
}


