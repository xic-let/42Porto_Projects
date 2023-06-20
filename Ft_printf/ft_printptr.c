/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:21:53 by acunha            #+#    #+#             */
/*   Updated: 2022/12/09 15:44:57 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_counthex(uintptr_t num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

void	ft_ptrtohexa(uintptr_t num)
{
	const char	base[17] = "0123456789abcdef";

	if (num >= 16)
	{
		ft_ptrtohexa(num / 16);
		ft_putchar_fd(base[num % 16], 1);
	}
	else
		ft_putchar_fd(base[num % 16], 1);
}

int	ft_printptr(uintptr_t ptr)
{
	int	index;

	index = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	else
	{
		index += write(1, "0x", 2);
		ft_ptrtohexa(ptr);
		index += ft_counthex(ptr);
	}
	return (index);
}
