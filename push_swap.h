/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:46:47 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/21 18:11:51 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	*stack_tmp;
	int	size_a;
	int	size_b;
}	t_stack;

// algorithm
void	iterative_quicksort(t_stack *a);
void	quicksort(int *stack_a, int size);
int		find_pivot(t_stack *a, int a_b);

// operations
void	ra(t_stack *a);
void	rb(t_stack *a);
void	rra(t_stack *a);
void	rrb(t_stack *a);
void	pb(t_stack *a);
void	pa(t_stack *a);
void	sa(t_stack *a);

// memory
void	fill_stack(t_stack *a, char **numbers);
int		allocate_memory(t_stack *a, char **argv);
void	free_memory(t_stack *a);

// errors
int		check_if_sorted(t_stack *a);
void	check_argv(int argc, char **argv);
void    check_duplicates(char **numbers);

// utils
void	ft_swap(int *a, int *b);
void	print_stack(int *stack, int	size);
void	ft_putstr(char *str);

#endif