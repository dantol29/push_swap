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

#ifndef CHECKER_H
# define CHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		*stack_tmp;
	int		size_b;
	int		size_tmp;
	int		size_a;
}	t_stack;

// algorithm
void	quicksort(int *stack_a, int	size);

// operations
void	ra(t_stack *a);
void	rb(t_stack *a);
void	rra(t_stack *a);
void	rrb(t_stack *a);
void	pb(t_stack *a);
void	pa(t_stack *a);
void	sa(t_stack *a);
void	sb(t_stack *a);
void	rrr(t_stack *a);
void	rr(t_stack *a);

// memory
void	allocate_memory(t_stack *a, char **argv, int argc);
void	free_memory_and_exit(t_stack *a, char *line, int status);

// errors
int		check_if_sorted(t_stack *a);
void	check_argv(int argc, char **argv);

// utils
void	ft_swap(int *a, int *b);
char	*get_next_line(int fd);

#endif