/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:46:47 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/01/04 10:23:25 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		*stack_tmp;
	int		size_a;
	int		size_b;
	int		*b_target;
	int		*cost_a;
	int		*cost_b;
}	t_stack;

// algorithm
void	sort_3(t_stack *a);
void	assign_index(t_stack *a);
void	rotate_and_push(t_stack *a, int cost_a, int cost_b);
void	rotate_b(t_stack *a, int cost_b);
void	rotate_a(t_stack *a, int cost_a);
void	solve(t_stack *a);

// operations
void	ra(t_stack *a);
void	rb(t_stack *a);
void	rra(t_stack *a);
void	rrb(t_stack *a);
void	pb(t_stack *a);
void	pa(t_stack *a);
void	sa(t_stack *a);

// memory
void	allocate_memory(t_stack *a, char **argv, int argc);
void	free_memory_and_exit(t_stack *a, int status);
void	free_tmp(char **tmp);

// errors
int		check_if_sorted(t_stack *a);
int		check_argv(char **numbers, int argc);
void	check_int(t_stack *a, char **tmp);
void	check_duplicate(t_stack *a);

// utils
void	quicksort(int *stack_a, int size);
void	ft_swap(int *a, int *b);
int		find_min(t_stack *a);
int		find_min_index(t_stack *a);
int		abs(int n);

#endif