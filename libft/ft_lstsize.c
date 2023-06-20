/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:17:14 by acunha            #+#    #+#             */
/*   Updated: 2022/11/22 14:36:59 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{	
	int		count;
	t_list	*jumper;

	count = 0;
	if (lst == NULL)
		return (count);
	jumper = lst;
	while (jumper)
	{
		jumper = jumper->next;
		count++;
	}
	return (count);
}
