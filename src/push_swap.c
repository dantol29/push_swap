/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:44:39 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/01/04 10:23:10 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_if_sorted(t_stack *a)
{
	ft_memcpy(a->stack_tmp, a->stack_a, a->size_a);
	quicksort(a->stack_tmp, a->size_a);
	if (ft_memcmp(a->stack_a, a->stack_tmp, a->size_a) == 0)
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

void	sort_3(t_stack *a)
{
	if (a->stack_a[0] > a->stack_a[1] && a->stack_a[1] > a->stack_a[2])
	{
		sa(a);
		rra(a);
		ft_putstr_fd("rra\n", 1);
	}
	if (a->stack_a[0] > a->stack_a[1] && a->stack_a[0] < a->stack_a[2])
		sa(a);
	if (a->stack_a[0] > a->stack_a[1] && a->stack_a[1] < a->stack_a[2])
	{
		ra(a);
		ft_putstr_fd("ra\n", 1);
	}
	if (a->stack_a[0] < a->stack_a[1] && \
	a->stack_a[1] > a->stack_a[2] && a->stack_a[0] > a->stack_a[2])
	{
		rra(a);
		ft_putstr_fd("rra\n", 1);
	}
	if (a->stack_a[0] < a->stack_a[1] && a->stack_a[1] > a->stack_a[2])
	{
		sa(a);
		ra(a);
		ft_putstr_fd("ra\n", 1);
	}
}

static void	sort(t_stack *a)
{
	if (a->size_a == 2 && check_if_sorted(a) != 1)
		sa(a);
	else if (a->size_a == 3)
		sort_3(a);
	else
	{
		while (a->size_a > 3)
			pb(a);
		sort_3(a);
		solve(a);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		size;

	size = check_argv(argv, argc);
	a = malloc(sizeof(t_stack));
	allocate_memory(a, argv, size);
	if (check_if_sorted(a) == 1)
		free_memory_and_exit(a, 0);
	assign_index(a);
	sort(a);
	free_memory_and_exit(a, 0);
}

// void	print_stack(int *stack, int	size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d ", stack[i]);
// 		i++;
// 	}
// 	printf("\n");
// }