/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorts_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochachi <ochachi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:11:54 by ochachi           #+#    #+#             */
/*   Updated: 2025/02/12 11:12:27 by ochachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*find_min(t_num *stack)
{
	t_num	*tmp;
	t_num	*min;

	tmp = stack;
	min = stack;
	while (tmp != NULL)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	extract_min(t_num **stack_a, int lstsize)
{
	t_num	*min;
	int		min_position;

	set_positions(stack_a, lstsize);
	min = find_min(*stack_a);
	min_position = min->position;
	if (lstsize == min_position)
		rra(stack_a);
	else if (lstsize == 5 && min_position == 4)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else
	{
		while (min_position > 1)
		{
			ra(stack_a);
			min_position--;
		}
	}
}
