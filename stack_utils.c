/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochachi <ochachi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:12:02 by ochachi           #+#    #+#             */
/*   Updated: 2025/02/12 11:12:21 by ochachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	new_num(int content)
{
	t_num	num;

	num.content = content;
	return (num);
}

int	is_stack_sorted(t_num *stack)
{
	t_num	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	add_node(int content, t_num **stack_a)
{
	t_num	*new_node;
	t_num	*tmp;

	if (!stack_a)
		return ;
	new_node = malloc(sizeof(t_num));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->position = 0;
	new_node->index = 0;
	new_node->next = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = new_node;
		return ;
	}
	tmp = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

int	index_stack(t_num *stack)
{
	t_num	*lst;
	t_num	*tmp;

	lst = stack;
	while (lst)
	{
		tmp = stack;
		while (tmp)
		{
			if (tmp != lst && lst->content == tmp->content)
			{
				ft_exit(stack, NULL);
				return (1);
			}
			if (tmp != lst && lst->content > tmp->content)
				lst->index++;
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}
