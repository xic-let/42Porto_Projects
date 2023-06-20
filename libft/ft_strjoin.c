/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:13:34 by acunha            #+#    #+#             */
/*   Updated: 2022/11/24 16:05:01 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		b;
	int		a;

	i = (ft_strlen(s1) + ft_strlen(s2));
	b = 0;
	a = 0;
	s3 = (char *)malloc(sizeof(char) * i +1);
	if (!s3)
		return (NULL);
	if (s1 && s2 && s3)
		while (s1[a] != '\0')
		s3[b++] = s1[a++];
	a = 0;
	while (s2[a] != '\0')
		s3[b++] = s2[a++];
	s3[b] = '\0';
	return (s3);
}
