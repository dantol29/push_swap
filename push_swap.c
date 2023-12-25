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

void	push_b_to_a(t_stack *a)
{
	int	size;
	int	i;

	size = a->size_b;
	i = 0;
	while (i < size)
	{
		pa(a);
		i++;
	}
}

void	modified_quicksort(t_stack *a)
{
	int	j;
	int	pivot;

	pivot = a->size_a - 1;
	if (a->size_a < 2 || a->stack_a == NULL)
		return ;
	j = 0;
	while (j <= pivot)
	{
		if (a->stack_a[pivot] > a->stack_a[j])
		{
			sa(a);
			pb(a);
			j = -1;
			pivot--;
		}
		else if (j == 1)
		{
			ra(a);
			pivot--;
			j = -1;
		}
		j++;
	}
}

int	find_min(t_stack *a)
{
	int	min;
	int	i;

	min = 2147483647;
	i = 0;
	while (i < a->size_a)
	{
		if (a->stack_a[i] < min)
			min = a->stack_a[i];
		i++;
	}
	return (min);
}

void	stupid_rra(t_stack *a, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		rra(a);
		i++;
	}
	pb(a);
}

void	stupid_ra(t_stack *a, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ra(a);
		i++;
	}
	pb(a);
}

void	stupid(t_stack *a)
{
	int	min;
	int	i;

	min = find_min(a);
	i = 0;
	while (i < a->size_a)
	{
		if (a->stack_a[i] == min)
		{
			if (a->size_a - i < a->size_a / 2)
				stupid_rra(a, a->size_a - i);
			else
				stupid_ra(a, i);
			min = find_min(a);
			i = -1;
		}
		i++;
	}
	push_b_to_a(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = malloc(sizeof(t_stack));
	a->size_a = argc - 1;
	a->size_b = 0;
	a->stack_a = (int *)malloc(sizeof(int) * a->size_a);
	if (a->stack_a == NULL)
		return (1);
	a->stack_b = (int *)malloc(sizeof(int) * a->size_a);
	if (a->stack_b == NULL)
	{
		free(a->stack_a);
		return (1);
	}
	i = 0;
	while (i < a->size_a)
	{
		a->stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	//modified_quicksort(a);
	stupid(a);
	print_stack(a->stack_a, a->size_a);
	print_stack(a->stack_b, a->size_b);
	free(a->stack_a);
	free(a->stack_b);
	free(a);
}

// void	quicksort(int *stack_a, int	size)
// {
// 	int	pivot;
// 	int	i;
// 	int	j;
// 	int	partition_index;

// 	if (size < 2 || stack_a == NULL)
// 		return ;
// 	pivot = stack_a[size - 1];
// 	i = -1;
// 	j = 0;
// 	while (j < size)
// 	{
// 		if (pivot > stack_a[j])
// 			ft_swap(&stack_a[j], &stack_a[++i]);
// 		j++;
// 	}
// 	ft_swap(&stack_a[size - 1], &stack_a[i + 1]);
// 	partition_index = i + 1;
// 	quicksort(stack_a, partition_index);
// 	quicksort(stack_a + partition_index + 1 , size - (partition_index + 1));
// }
