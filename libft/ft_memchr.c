/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:47:43 by acunha            #+#    #+#             */
/*   Updated: 2022/11/24 15:03:22 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*src;

	src = (const unsigned char *)str;
	while (n)
	{
		if (*src == (unsigned char)c)
			return ((void *)src);
		src++;
		n--;
	}
	return (NULL);
}
