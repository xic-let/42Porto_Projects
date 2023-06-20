/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtunsg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:10:09 by acunha            #+#    #+#             */
/*   Updated: 2022/12/09 15:45:04 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static unsigned int	uns_num(unsigned int n)
{
	int	nbr;

	nbr = 0;
	while (n != 0)
	{
		n = n / 10;
		nbr++;
	}
	return (nbr);
}

int	ft_prtunsg(unsigned int nbr)
{
	unsigned int	n;
	char			*res;
	int				i;

	if (nbr == 0)
		return (write(1, "0", 1));
	n = uns_num(nbr);
	i = n;
	res = malloc((n + 1) * (sizeof(char)));
	if (!res)
		return (0);
	res[n--] = '\0';
	while (nbr != 0)
	{
		res[n--] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	ft_putstr(res);
	free (res);
	return (i);
}
