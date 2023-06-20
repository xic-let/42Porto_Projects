/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:39:08 by acunha            #+#    #+#             */
/*   Updated: 2023/05/01 10:56:11 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_path(char **envp) // esta funcao vai desdobrar o path
{
	char	*envp_path;
	char	**path_bits;
	int		i;

	envp_path = NULL;
	path_bits = NULL;
	i = 0;
	while (envp[i]) // este loop serve para comparar e verificar se o envp comecao pela palavra PATH. se encontrar, vai criar espaco na memoria para e duplpicar a a string atraves do srtdup
	{	
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			envp_path = ft_strdup(envp[i]);
			if (!envp_path)
				ft_error(ERROR_ENVP, "errno", 1); // se nao encontrar vai retornar erro
			break ;
		}
		i++;
	}
	if (!envp_path)
		ft_error(ERROR_ENVPATH, "errno", 1);
	path_bits = ft_split(envp_path, ':'); //depois vai usar a funcao split para dividir pelo : e alocar o conteudo em path_biths nos diretorios individuais da variavel PATH
	free(envp_path); // liberta a memoria desnecess'aria.
	return (path_bits);
}

char	*ft_get_cmd_path(char **envp, char *cmd_part) // esta funcao serve para encontrar o caminho completo para um ficheiro executavel com um comando a determinar.
{
	char	**path_bits;
	char	*ver_path;
	char	*cmd;
	int		i;

	i = 0;
	if (access(cmd_part, F_OK | X_OK) == 0) // verifica se o argumento dado na funcao pode ser acedio e executado 
		return (cmd_part); // se for, devolve o caminho
	path_bits = ft_get_path(envp); //se nao for um comando executavel, vai chamar a funcao acima para ir buscar os diretorios ao PATH, e o desmembrar devolvendo o resultado a path bits.
	cmd = ft_strjoin("/", cmd_part); //depois aloca memoria e coloca / em cmd part, formando assim a string que vai representar o comando.
	while (path_bits[i])
	{
		ver_path = ft_strjoin(path_bits[i], cmd); // dentro do loop vai juntar o resultado do caminho alocado em cima com o conteudo da string cmd, criando assim a string que vai dar o caminho completo.
		if (access(ver_path, F_OK | X_OK) == 0) // se o retorno nao for um executavel, vai libertar o espa;o de memoria, vai fazer um reset no verificados de caminho e depois incrementar para avancar para o proximo diretorio de path biths
			break ;
		free(ver_path);
		ver_path = NULL;
		i++;
	}
	i--; // ao sair do loop vai decrementar pra referenciar o ultimo diretorio valido 
	while (path_bits[++i]) // depois liberta memorias que possam estar a ser desperdicadas
		free(path_bits[i]);
	free(path_bits);
	free(cmd);
	return (ver_path); 
}
