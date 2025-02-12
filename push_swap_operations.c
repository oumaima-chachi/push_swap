/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochachi <ochachi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:11:34 by ochachi           #+#    #+#             */
/*   Updated: 2025/02/12 11:12:44 by ochachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_num **stack_a, t_num **stack_b)
{
	t_num	*tmp;

	tmp = (*stack_a);
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_b);
	*stack_b = tmp;
	write(1, "pb\n", 3);
}

void	pa(t_num **stack_a, t_num **stack_b)
{
	t_num	*tmp;

	tmp = (*stack_b);
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_a);
	*stack_a = tmp;
	write(1, "pa\n", 3);
}

void	sa(t_num **stack_a)
{
	t_num	*third;
	t_num	*second;

	third = (*stack_a)->next->next;
	second = (*stack_a)->next;
	(*stack_a)->next = third;
	second->next = (*stack_a);
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	sb(t_num **stack_b)
{
	t_num	*third;
	t_num	*second;

	third = (*stack_b)->next->next;
	second = (*stack_b)->next;
	(*stack_b)->next = third;
	second->next = (*stack_b);
	*stack_b = second;
	write(1, "sb\n", 3);
}

void	ss(t_num **stack_a, t_num **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
