/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:23:56 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/01/04 09:24:24 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	pa(t_stack *a)
{
	int	i;

	if (a->size_b > 0)
	{
		i = a->size_a;
		while (i > 0)
		{
			a->stack_a[i] = a->stack_a[i - 1];
			i--;
		}
		a->stack_a[0] = a->stack_b[0];
		i = 0;
		while (i < a->size_b - 1)
		{
			a->stack_b[i] = a->stack_b[i + 1];
			i++;
		}
		a->size_b--;
		a->size_a++;
	}
}

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size_a > 0)
	{
		i = 0;
		temp = a->stack_a[0];
		while (i < a->size_a - 1)
		{
			a->stack_a[i] = a->stack_a[i + 1];
			i++;
		}
		a->stack_a[a->size_a - 1] = temp;
	}
}

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size_a > 0)
	{
		i = 0;
		temp = a->stack_a[a->size_a - 1];
		i = a->size_a - 1;
		while (i > 0)
		{
			a->stack_a[i] = a->stack_a[i - 1];
			i--;
		}
		a->stack_a[0] = temp;
	}
}

void	sa(t_stack *a)
{
	int	temp;

	if (a->size_a > 1)
	{
		temp = a->stack_a[1];
		a->stack_a[1] = a->stack_a[0];
		a->stack_a[0] = temp;
	}
}

void	rrr(t_stack *a)
{
	rra(a);
	rrb(a);
}
