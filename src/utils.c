/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:48:06 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/21 19:01:40 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

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

int	find_max_index(t_stack *a)
{
	int	max;
	int	i;
	int	index;

	max = -2147483648;
	i = 0;
	index = 0;
	while (i < a->size_b)
	{
		if (a->stack_b[i] > max)
		{
			max = a->stack_b[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	find_max(t_stack *a)
{
	int	max;
	int	i;

	max = -2147483648;
	i = 0;
	while (i < a->size_b)
	{
		if (a->stack_b[i] > max)
			max = a->stack_b[i];
		i++;
	}
	return (max);
}

int	find_min_index(t_stack *a)
{
	int	min;
	int	i;
	int	index;

	min = 2147483647;
	i = 0;
	index = 0;
	while (i < a->size_a)
	{
		if (a->stack_a[i] < min)
		{
			min = a->stack_a[i];
			index = i;
		}
		i++;
	}
	return (index);
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

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	print_stack(int *stack, int	size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", stack[i]);
		i++;
	}
	printf("\n");
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, str + i, 1);
		i++;
	}
}