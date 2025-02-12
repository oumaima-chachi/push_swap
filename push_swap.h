/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochachi <ochachi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:11:43 by ochachi           #+#    #+#             */
/*   Updated: 2025/02/12 11:12:38 by ochachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_num
{
	int				content;
	int				index;
	int				position;
	struct s_num	*next;
}					t_num;
void	set_positions(t_num **stack, int lstsize);
int		is_stack_sorted(t_num *stack);
void	parsing(int argc, char **argv, t_num **stack_a, int *lstsize);
int		are_args_valid(int argc, char **argv);
char	**ft_split(const char *s, char c);
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	sort_two(t_num **stack_a);
void	sort_three(t_num **stack_a);
void	sort_four(t_num **stack_a, t_num **stack_b, int lstsize);
void	sort_five(t_num **stack_a, t_num **stack_b, int lstsize);
void	sort_short_stack(t_num **stack_a, t_num **stack_b, int lstsize);
t_num	*find_min(t_num *stack);
void	extract_min(t_num **stack_a, int lstsize);
t_num	new_num(int content);
int		is_stack_sorted(t_num *stack);
void	add_node(int content, t_num **stack_a);
int		index_stack(t_num *stack);
void	ft_free_array(char **array);
void	ft_free_list(t_num *lst);
void	ft_exit(t_num *lst, char **array);
void	sa(t_num **stack_a);
void	sb(t_num **stack_b);
void	ss(t_num **stack_a, t_num **stack_b);
void	pb(t_num **stack_a, t_num **stack_b);
void	pa(t_num **stack_a, t_num **stack_b);
void	ra(t_num **stack_a);
void	rb(t_num **stack_b);
void	rr(t_num **stack_a, t_num **stack_b);
void	rra(t_num **stack_a);
void	rrb(t_num **stack_b);
void	rrr(t_num **stack_a, t_num **stack_b);
void	ft_exit(t_num *lst, char **array);
#endif