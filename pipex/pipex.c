/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:22:25 by acunha            #+#    #+#             */
/*   Updated: 2023/05/01 11:08:34 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(int *fd)
{
	close(fd[0]);
	close(fd[1]); // a funcao utilizada para fechar os filedescriptors
}

int	main(int argc, char **argv, char **envp) // a fncao principal toma 3 argumentos, o argc vai contar os argumentos da linha de comandos, argv o array de strings que contem os argumentos, e o envp 'e o array de strings que contem as variaveis de ambiente.
{
	pid_t	pid;
	int		fd[2];

	if (argc == 5)// verifica o numero de argumentos necess'arios para avancar com a execucao, senao imprime erro, sai do programa e devolve o valor 1
	{
		if (pipe(fd) == -1) 
			ft_error(ERROR_PIPE, "errno", 1); 
		pid = fork(); // com o numero de argumentos correto o programa cria um pipe e guarda os fd no array fd, depois cria um child process atraves do comando fork 
		if (pid == -1)
			ft_error(ERROR_FORK, "errno", 1);
		if (pid == 0) // se o processo criado pelo fork retornar 0 significa que 'e o child process. o processo principal chama a funcao waitpid para entrar em pausa enquanto o processo child se executa e aguarda que termine. apos o termino da funcao child 1, entra a funcao chil2 que vai executar o codigo do codigo pai.
			ft_childp1(argv, envp, fd);
		waitpid(pid, NULL, 0);
		ft_childp2(argv, envp, fd);
	}
	else
		ft_error(ERROR_ARG, "errno", 1);
	return (0);
}
