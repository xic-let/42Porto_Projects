/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:15:20 by acunha            #+#    #+#             */
/*   Updated: 2022/11/24 16:02:58 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	t;
	size_t	i;

	t = size * nmemb;
	str = malloc(t);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (t > 0)
	{
		str[i] = 0;
		i++;
		t--;
	}
	return ((void *)str);
}
