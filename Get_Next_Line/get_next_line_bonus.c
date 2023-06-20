/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:29:12 by acunha            #+#    #+#             */
/*   Updated: 2023/03/08 12:25:26 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdio.h>


char	*ft_read_this_line(int fd, char *str)
{
	char	*new_line;
	int		reader;

	new_line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	reader = 1;
	while (!ft_strchr(str, '\n') && reader != 0)
	{
		reader = read(fd, new_line, BUFFER_SIZE);
		if (reader == -1)
		{
			free (new_line);
			free(str);
			return (NULL);
		}
		new_line[reader] = '\0';
		str = ft_strjoin(str, new_line);
	}
	free (new_line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[FD_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (0);
	str[fd] = ft_read_this_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_extract_line(str[fd]);
	str[fd] = ft_new_line (str[fd]);
	return (line);
}
