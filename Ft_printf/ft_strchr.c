/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:51:43 by acunha            #+#    #+#             */
/*   Updated: 2022/12/09 15:45:12 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int c)
{
	while (c != *str && *str)
		str++;
	if (*str == c)
		return ((char *)str);
	return (0);
}
