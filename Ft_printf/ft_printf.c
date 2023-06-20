/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:12:02 by acunha            #+#    #+#             */
/*   Updated: 2022/12/09 15:44:49 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<unistd.h>

int	ft_printf(const char *format, ...)
{
	int		num_args;
	int		i;
	va_list	args;

	i = 0;
	num_args = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			num_args += ft_handleformat(args, format[i + 1]);
			i++;
		}
		else
			num_args += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (num_args);
}
