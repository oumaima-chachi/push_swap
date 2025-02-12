/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochachi <ochachi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:11:18 by ochachi           #+#    #+#             */
/*   Updated: 2025/02/12 11:13:22 by ochachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_list(t_num *lst)
{
	t_num	*tmp;

	tmp = lst;
	while (tmp)
	{
		lst = tmp->next;
		free(tmp);
		tmp = lst;
	}
}

void	ft_exit(t_num *lst, char **array)
{
	if (lst)
		ft_free_list(lst);
	if (array)
		ft_free_array(array);
	write(2, "Error\n", 6);
	exit(0);
}
