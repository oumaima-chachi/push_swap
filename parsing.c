/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochachi <ochachi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:11:31 by ochachi           #+#    #+#             */
/*   Updated: 2025/02/12 11:12:47 by ochachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(int argc, char **argv, t_num **stack_a, int *lstsize)
{
	int		i;
	int		j;
	char	**nums;
	long	split;

	i = 1;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		if (!nums)
			ft_exit((*stack_a), nums);
		j = 0;
		while (nums[j])
		{
			split = ft_atoi(nums[j]);
			if (split > 2147483647 || split < -2147483648)
				ft_exit((*stack_a), nums);
			add_node(split, stack_a);
			j++;
		}
		ft_free_array(nums);
		*lstsize += j;
		i++;
	}
}

int	are_args_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9') ||
				argv[i][j] == ' ' || argv[i][j] == '+' || argv[i][j] == '-')
				j++;
			else
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
