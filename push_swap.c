/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:44:39 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/22 16:18:11 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// regular quicksort to find pivot
void	quicksort(int *stack_a, int	size)
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
	quicksort(stack_a + partition_index + 1 , size - (partition_index + 1));
}

// int	find_pivot(t_stack *a, int a_b)
// {
// 	if (a_b == 0)
// 	{
// 		ft_memcpy(a->stack_tmp, a->stack_a, a->size_a);
// 		quicksort(a->stack_tmp, a->size_a);
// 		return (a->stack_tmp[(a->size_b - 1) / 2]);
// 	}
// 	else if (a_b == 1)
// 	{
// 		ft_memcpy(a->stack_tmp, a->stack_b, a->size_b);
// 		quicksort(a->stack_tmp, a->size_b);
// 		return (a->stack_tmp[(a->size_b - 1) / 2]);
// 	}
// 	return (0);
// }

// void	iterative_quicksort(t_stack *a)
// {
// 	int	pivot;
// 	int	j;
// 	int	size;
// 	int	pa_count;
// 	//int	partition_index;
// 	j = 0;
// 	while (j != 42)
// 	{
// 		while (a->size_a > 3)
// 		{
// 			j = 0;
// 			size = a->size_a;
// 			pivot = find_pivot(a, 0);
// 			printf("%d pivot\n", pivot);
// 			while (j < size && a->size_a > 3)
// 			{
// 				if (pivot >= a->stack_a[0])
// 					pb(a);
// 				else
// 					ra(a);
// 				j++;
// 			}
// 		}
// 		//sort_3(a);
// 		j = 0;
// 		pa_count = 0;
// 		size = a->size_b;
// 		pivot = find_pivot(a, 1);
// 		printf("%d pivot\n", pivot);
// 		while (j < size)
// 		{
// 			if (pivot < a->stack_b[0])
// 			{
// 				pa(a);
// 				pa_count++;
// 			}
// 			else
// 				rb(a);
// 			j++;
// 		}
// 		//if (pa_count <= 3)
// 		sort_3(a);
// 		j = 42;
// 	}
// }

// pivot == min and then next_min and so on until stack a is not empty

int	find_min(t_stack *a)
{
	int	i;
	int	min;

	i = 0;
	min = 2147483647;
	while (i < a->size_a)
	{
		if (a->stack_a[i] < min)
			min = a->stack_a[i];
		i++;
	}
	i = 0;
	while (a->stack_a[i] != min)
		i++;
	return (i);
}

void	sort_3(t_stack *a)
{
	// 3 2 1
	if (a->stack_a[0] > a->stack_a[1] && a->stack_a[1] > a->stack_a[2])
	{
		sa(a);
		rra(a);
	}
	// 2 1 3
	if (a->stack_a[0] > a->stack_a[1] && a->stack_a[0] < a->stack_a[2])
		sa(a);
	// 3 1 2
	if (a->stack_a[0] > a->stack_a[1] && a->stack_a[1] < a->stack_a[2])
		ra(a);
	// 2 3 1
	if (a->stack_a[0] < a->stack_a[1] && a->stack_a[1] > a->stack_a[2] && a->stack_a[0] > a->stack_a[2])
		rra(a);
	// 1 3 2
	if (a->stack_a[0] < a->stack_a[1] && a->stack_a[1] > a->stack_a[2])
	{
		sa(a);
		ra(a);
	}
}

int	push_to_b(t_stack *a)
{
	int	min;

	while (a->size_a > 3)
	{
		min = find_min(a);
		if (a->size_a / 2 >= min)
		{
			min = a->stack_a[min];
			while (a->stack_a[0] != min)
				ra(a);
			if (check_if_sorted(a) == 1)
				break ;
			pb(a);
		}
		else
		{
			min = a->stack_a[min];
			while (a->stack_a[0] != min)
				rra(a);
			if (check_if_sorted(a) == 1)
				break ;
			pb(a);
		}
	}
	sort_3(a);
	while (a->size_b > 0)
		pa(a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	check_argv(argc, argv);
	check_duplicates(ft_split(argv[1], ' '));
	a = malloc(sizeof(t_stack));
	if (allocate_memory(a, argv) == 1)
		exit(EXIT_FAILURE);
	fill_stack(a, ft_split(argv[1], ' '));
	if (check_if_sorted(a) == 1)
		return (0);
	push_to_b(a);
	print_stack(a->stack_a, a->size_a);
	print_stack(a->stack_b, a->size_b);
	free_memory(a);
}