/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochachi <ochachi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:11:57 by ochachi           #+#    #+#             */
/*   Updated: 2025/02/12 11:12:24 by ochachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_num **stack_a)
{
	t_num	*tmp;

	tmp = (*stack_a);
	if (tmp->content > tmp->next->content)
		sa(stack_a);
}

void	sort_three(t_num **stack_a)
{
	t_num	*tmp;

	tmp = (*stack_a);
	if (tmp->content > tmp->next->content
		&& tmp->content > tmp->next->next->content)
	{
		ra(stack_a);
		sort_two(stack_a);
	}
	else if (tmp->content < tmp->next->next->content
		&& tmp->next->content < tmp->next->next->content)
		sort_two(stack_a);
	else if (tmp->content < tmp->next->content
		&& tmp->next->content > tmp->next->next->content)
	{
		rra(stack_a);
		sort_two(stack_a);
	}
}

void	sort_four(t_num **stack_a, t_num **stack_b, int lstsize)
{
	extract_min(stack_a, lstsize);
	if (is_stack_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_num **stack_a, t_num **stack_b, int lstsize)
{
	extract_min(stack_a, lstsize);
	if (is_stack_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b, lstsize - 1);
	pa(stack_a, stack_b);
}

void	sort_short_stack(t_num **stack_a, t_num **stack_b, int lstsize)
{
	if (lstsize == 5)
		sort_five(stack_a, stack_b, lstsize);
	else if (lstsize == 4)
		sort_four(stack_a, stack_b, lstsize);
	else if (lstsize == 3)
		sort_three(stack_a);
	else if (lstsize == 2)
		sort_two(stack_a);
	else
		return ;
}
