/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:44:39 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/01/04 09:25:36 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	check_if_sorted(t_stack *a)
{
	ft_memcpy(a->stack_b, a->stack_tmp, a->size_tmp);
	quicksort(a->stack_b, a->size_a);
	if (ft_memcmp(a->stack_a, a->stack_b, a->size_tmp) != 0)
		return (1);
	return (0);
}

void	quicksort(int *stack_a, int size)
{
	int	pivot;
	int	i;
	int	j;
	int	partition_index;

	if (size < 2 || stack_a == NULL)
		return ;
	pivot = stack_a[size - 1];
	i = -1;
	j = 0;
	while (j < size)
	{
		if (pivot > stack_a[j])
			ft_swap(&stack_a[j], &stack_a[++i]);
		j++;
	}
	ft_swap(&stack_a[size - 1], &stack_a[i + 1]);
	partition_index = i + 1;
	quicksort(stack_a, partition_index);
	quicksort(stack_a + partition_index + 1, size - (partition_index + 1));
}

static int	do_instructions(t_stack *a, char *input)
{
	if (ft_strcmp(input, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(input, "rb\n") == 0)
		rb(a);
	else if (ft_strcmp(input, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(input, "rrb\n") == 0)
		rrb(a);
	else if (ft_strcmp(input, "rr\n") == 0)
		rr(a);
	else if (ft_strcmp(input, "rrr\n") == 0)
		rrr(a);
	else if (ft_strcmp(input, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(input, "sb\n") == 0)
		sb(a);
	else if (ft_strcmp(input, "pa\n") == 0)
		pa(a);
	else if (ft_strcmp(input, "pb\n") == 0)
		pb(a);
	else
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	char	*line;
	int		size;

	size = check_argv(argv, argc);
	a = malloc(sizeof(t_stack));
	allocate_memory(a, argv, size);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (do_instructions(a, line) == 1)
		{
			ft_putstr_fd("Error\n", 2);
			free(line);
			free_memory_and_exit(a, 1);
		}
		free(line);
		line = get_next_line(0);
	}
	if (a->size_b == 0 && check_if_sorted(a) == 0)
		free_memory_and_exit(a, 0);
	ft_putstr_fd("KO\n", 1);
	free_memory_and_exit(a, 1);
}
