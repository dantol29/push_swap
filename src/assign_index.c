/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:34:18 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/01/04 09:43:30 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_used_index(int *used_index, int size, int i)
{
	int	status;

	status = 0;
	while (size > 0)
	{
		if (used_index[size - 1] == i)
			status = 1;
		size--;
	}
	return (status);
}

int	find_next_min(t_stack *a, int *used_index, int size)
{
	int	i;
	int	min;
	int	status;

	i = 0;
	min = 2147483647;
	while (i < a->size_a)
	{
		if (a->stack_a[i] < min)
		{
			status = check_used_index(used_index, size, i);
			if (status != 1)
				min = a->stack_a[i];
		}
		i++;
	}
	i = 0;
	while (a->stack_a[i] != min)
		i++;
	return (i);
}

void	assign_index(t_stack *a)
{
	int	min;
	int	index;
	int	*used_index;

	ft_memcpy(a->stack_tmp, a->stack_a, a->size_a);
	used_index = ft_calloc(a->size_a, sizeof(int));
	index = 1;
	while (index < a->size_a + 1)
	{
		min = find_next_min(a, used_index, index - 1);
		a->stack_tmp[min] = index;
		used_index[index - 1] = min;
		index++;
	}
	ft_memcpy(a->stack_a, a->stack_tmp, a->size_a);
	free(used_index);
}
