/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:39:32 by acunha            #+#    #+#             */
/*   Updated: 2023/05/01 11:08:52 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H // definicao do header file
# define PIPEX_H 

# include <fcntl.h> //bibliotecas necess'arias para executar a funcao
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define TRUE 1 // definicao de constantes para lidar com os erros que possam aparecer
# define FALSE 0
# define ERROR_ARG "Error: wrong number of arguments\n"
# define ERROR_PIPE "Error: pipe failed\n"
# define ERROR_FORK "Error: fork failed\n"
# define ERROR_OPENO "Error: open failed\n"
# define ERROR_OPENI "Error: open failed\n"
# define ERROR_CMD "Error: command not found\n"
# define ERROR_EXECVE "Error: execve failed\n"
# define ERROR_ENVP "Error: duplicate enviroment path failed\n"
# define ERROR_ENVPATH "Error: enviroment path not found\n"

void	ft_close(int *fd);
void	ft_error(char *str, char *msg, int exit_code);
void	ft_childp1(char **argv, char **envp, int *fd);
void	ft_childp2(char **argv, char **envp, int *fd);
int		main(int argc, char **argv, char **envp);
char	**ft_get_path(char **envp);
char	*ft_get_cmd_path(char **envp, char *cmd_part);
void	ft_cmd(char *cmd1, char **envp);
size_t	wordlen(char const *s, char c);
size_t	wordcount(char const *s, char c);
char	*wordcpy(char *dst, const char *src, char c);
char	**ft_free(char **ret, int j);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
