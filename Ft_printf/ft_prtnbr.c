/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:00:33 by acunha            #+#    #+#             */
/*   Updated: 2022/12/09 15:45:02 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_prtnbr(int i)
{
	int		index;
	char	*nbr;

	index = 0;
	nbr = ft_itoa(i);
	index = ft_putstr(nbr);
	free (nbr);
	return (index);
}
