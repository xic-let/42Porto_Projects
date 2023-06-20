/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:24:06 by acunha            #+#    #+#             */
/*   Updated: 2022/12/14 13:39:22 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*ft_read_this_line(int fd, char *str)
{
	char	*new_line;
	int		reader;

	new_line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new_line)
		return (0);
	reader = 1;
	while (!ft_strchr(str, '\n') && reader != 0)
	{
		reader = read(fd, new_line, BUFFER_SIZE);
		if (reader == -1)
		{
			free (new_line);
			free (str);
			return (0);
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
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_this_line(fd, str);
	if (!str)
	{
		return (0);
	}
	line = ft_extract_line(str);
	str = ft_new_line(str);
	return (line);
}
