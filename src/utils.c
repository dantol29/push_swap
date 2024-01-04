/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:48:06 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/01/04 09:44:58 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
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
