/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:52:50 by acunha            #+#    #+#             */
/*   Updated: 2022/11/24 14:04:43 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat( char *dst, const char *src, size_t size)
{
	size_t	newsize;
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	dstlen = ft_strlen(dst);
	if (size < dstlen)
		return (srclen + size);
	newsize = 0;
	while (src[newsize] && dstlen + newsize < (size -1))
	{
		dst[dstlen + newsize] = src[newsize];
		newsize++;
	}
	dst[dstlen + newsize] = '\0';
	return (dstlen + srclen);
}
