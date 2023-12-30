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

#include "../includes/push_swap.h"

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
	if (a->stack_a[0] < a->stack_a[1] && a->stack_a[1] > a->stack_a[2] && a->stack_a[0] > a->stack_a[2])
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

	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	check_argv(argc, argv);
	check_duplicates(argc, argv);
	a = malloc(sizeof(t_stack));
	allocate_memory(a, argv, argc);
	if (check_if_sorted(a) == 1)
		free_memory_and_exit(a);
	assign_index(a);
	sort(a);
	print_stack(a->stack_a, a->size_a);
	print_stack(a->stack_b, a->size_b);
	free_memory_and_exit(a);
}