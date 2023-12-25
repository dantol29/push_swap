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

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
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

void	pb(t_stack *a)
{
	int	i;

	i = a->size_b;
	while (i > 0)
	{
		a->stack_b[i] = a->stack_b[i - 1];
		i--;
	}
	a->stack_b[0] = a->stack_a[0];
	i = 0;
	while (i < a->size_a - 1)
	{
		a->stack_a[i] = a->stack_a[i + 1];
		i++;
	}
	a->size_a--;
	a->size_b++;
	printf("pb\n");
}

void	pa(t_stack *a)
{
	int	i;

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
	printf("pa\n");
}
void	ra(t_stack *a)
{
	int	temp;
	int	i;

	i = 0;
	temp = a->stack_a[0];
	while (i < a->size_a - 1)
	{
		a->stack_a[i] = a->stack_a[i + 1];
		i++;
	}
	a->stack_a[a->size_a - 1] = temp;
	printf("ra\n");
}

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	i = 0;
	temp = a->stack_a[a->size_a - 1];
	i = a->size_a - 1;
	while (i > 0)
	{
		a->stack_a[i] = a->stack_a[i - 1];
		i--;
	}
	a->stack_a[0] = temp;
	printf("rra\n");
}

void	sa(t_stack *a)
{
	int temp;

	temp = a->stack_a[1];
	a->stack_a[1] = a->stack_a[0];
	a->stack_a[0] = temp;
	printf("sa\n");
}