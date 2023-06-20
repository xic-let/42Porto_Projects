/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleformat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:25:14 by acunha            #+#    #+#             */
/*   Updated: 2022/12/09 15:44:38 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handleformat(va_list args, const char format)
{
	if (format == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_printptr(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_prtnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_prtunsg(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_prthex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_printpercent());
	return (0);
}
