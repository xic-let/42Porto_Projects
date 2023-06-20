/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:30:06 by acunha            #+#    #+#             */
/*   Updated: 2023/05/01 15:30:44 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str, char *msg, int exit_code)
{
	if (!str)
		perror("pipex error");
	else
	{
		ft_putstr_fd(str, 2);
		perror(msg);
	}
	exit(exit_code);
}
