/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:29:24 by acunha            #+#    #+#             */
/*   Updated: 2023/03/08 12:26:00 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

#  define BUFFER_SIZE 9999
#  define FD_MAX 1024

char	*get_next_line(int fd);
char	*ft_read_this_line(int fd, char *str);
size_t	ft_strlen(char *x);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_extract_line(char *ch);
char	*ft_new_line(char *str);

#endif
