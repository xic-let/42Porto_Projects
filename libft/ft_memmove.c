/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:49:07 by acunha            #+#    #+#             */
/*   Updated: 2022/11/24 12:29:39 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (src == dest)
		return (0);
	if (d < s)
		while (n--)
		*d++ = *s++;
	else
	{
		s = s + (n -1);
		d = d + (n -1);
		while (n--)
		*d-- = *s--;
	}
	return (dest);
}
