/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:29:45 by acunha            #+#    #+#             */
/*   Updated: 2022/11/24 16:05:44 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s3;
	size_t	bg;
	size_t	end;

	s3 = 0;
	if (s1 != 0 && set != 0)
	{
		bg = 0;
		end = ft_strlen(s1);
		while (s1[bg] && ft_strchr(set, s1[bg]))
			bg++;
		while (s1[end -1] && ft_strchr(set, s1[end -1]) && end > bg)
			end--;
		s3 = (char *)malloc(sizeof(char) * (end - bg +1));
		if (s3)
			ft_strlcpy(s3, &s1[bg], (end - bg) + 1);
	}
	return (s3);
}
