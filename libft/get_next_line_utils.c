/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:24:28 by acunha            #+#    #+#             */
/*   Updated: 2022/12/14 13:37:57 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"


char	*ft_strjoin2(char *s1, char *s2)
{
	char	*s3;
	int		b;
	int		a;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	s3 = malloc(sizeof(char) * ((ft_strlen(s1)) + (ft_strlen(s2)) + 1));
	if (!s3)
		return (0);
	b = -1;
	a = 0;
	if (s1)
		while (s1[++b] != '\0')
			s3[b] = s1[b];
	while (s2[a] != '\0')
		s3[b++] = s2[a++];
	s3[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	s3[b] = '\0';
	free (s1);
	return (s3);
}

char	*ft_extract_line(char *ch)
{
	int		i;
	char	*str;

	i = 0;
	if (!ch[i])
		return (NULL);
	while (ch[i] && ch[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (ch[i] && ch[i] != '\n')
	{
		str[i] = ch[i];
		i++;
	}
	if (ch[i] == '\n')
	{
		str[i] = ch[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_line(char *str)
{
	int		i;
	int		x;
	char	*buf;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!buf)
		return (NULL);
	i++;
	x = 0;
	while (str[i])
		buf[x++] = str[i++];
	buf[x] = '\0';
	free(str);
	return (buf);
}
