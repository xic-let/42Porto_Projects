/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:04:22 by acunha            #+#    #+#             */
/*   Updated: 2023/05/01 10:59:38 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cmd(char *cmd1, char **envp) // esta funcao vai lidar com a execucao do comando, dividindo em argumentos. 
{
	char	**cmd_args; // e um pointer para um pointer que guarda os argumentos dos comando
	char	*path; // o pointer para guardar o caminho para o comando executavel
	int		i;

	cmd_args = ft_split(cmd1, ' '); // vai usar o split para dividir o cmd1 em argumentos individuais usando o espaco como delimitador e o resultado vai ser guardado na variavl
	path = ft_get_cmd_path(envp, cmd_args[0]); // a variavel vai criar o caminho para o executavel
	if (!path || !cmd_args)
	{
		i = -1;
		while (cmd_args[++i])
			free(cmd_args[i]);
		free(cmd_args);
		ft_error(ERROR_CMD, "errno", 1);
	}
	execve(path, cmd_args, envp); //A função execve carrega o novo programa em memória, substitui o código e os dados do processo atual pelos do novo programa e inicia a execução a partir do ponto de entrada do novo programa.
	ft_error(ERROR_EXECVE, "errno", 1);
}

void	ft_childp1(char **argv, char **envp, int *fd)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY, 0777);  //Ela recebe três parâmetros: argv (um array de strings que contém os argumentos do programa), envp (um array de strings que contém as variáveis de ambiente) e fd (um ponteiro para um array de inteiros).
//A função abre um arquivo em modo de leitura apenas (O_RDONLY) e usa o primeiro argumento argv[1]. O arquivo é aberto com permissões de leitura, escrita e execução para todos (0777).
	if (file1 == -1)
		ft_error(ERROR_OPENI, "errno", 0);
	dup2(fd[1], STDOUT_FILENO); //a função redireciona a saída padrão (STDOUT_FILENO) para o descritor de arquivo fd[1] usando dup2. Isso significa que o que for escrito na saída padrão será redirecionado para fd[1].
//Da mesma forma, a função redireciona a entrada padrão (STDIN_FILENO) para o arquivo que foi aberto (file1) usando dup2. Isso significa que o que for lido da entrada padrão será redirecionado para o arquivo file1.
	dup2(file1, STDIN_FILENO);
	close(file1);
	ft_close(fd);
	ft_cmd(argv[2], envp);  //Por fim, a função ft_cmd é chamada com argv[2] e envp como argumentos. e executa um comando ou programa com base nos argumentos fornecidos.
}

void	ft_childp2(char **argv, char **envp, int *fd)
{
	int	file2;

	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777); //abre um arquivo em modo de escrita (O_WRONLY), criando o arquivo se ele não existir (O_CREAT) e truncando o arquivo para zero bytes se ele existir (O_TRUNC). O nome do arquivo é obtido a partir do quinto argumento argv[4]. O arquivo é aberto com permissões de leitura, escrita e execução para todos (0777).
	if (file2 == -1)
		ft_error(ERROR_OPENO, "errno", 1);
	dup2(fd[0], STDIN_FILENO);  // função redireciona a entrada padrão (STDIN_FILENO) para o descritor de arquivo fd[0] usando dup2. Isso significa que o que for lido da entrada padrão será redirecionado para fd[0].

	dup2(file2, STDOUT_FILENO);//Da mesma forma, a função redireciona a saída padrão (STDOUT_FILENO) para o arquivo que foi aberto (file2) usando dup2. Isso significa que o que for escrito na saída padrão será redirecionado para o arquivo file2.
	close(file2);
	ft_close(fd); //Após fazer os redirecionamentos, o arquivo file2 é fechado usando close.
	ft_cmd(argv[3], envp);  // a função ft_cmd é chamada com argv[3] e envp como argumentos. Assim como na função ft_childp1, essa função provavelmente executa um comando ou programa com base nos argumentos fornecidos.
}
