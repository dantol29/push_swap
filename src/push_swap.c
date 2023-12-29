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

void	check_biggest(t_stack *a, int number)
{
	int	min;
	int	i;

	i = 0;
	if (number > find_max(a))
	{
		min = find_min_index(a);
		//printf("\n\n%d maxn\n\n\n", number);
		//print_stack(a->stack_b, a->size_b);
		if (a->size_b / 2 >= min)
		{
			while (i++ < min)
				rb(a);
		}
		else
		{
			while (i++ < a->size_b - min)
				rrb(a);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	check_argv(argc, argv);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	check_duplicates(argv);
	a = malloc(sizeof(t_stack));
	allocate_memory(a, argv);
	if (check_if_sorted(a) == 1)
		free_memory_and_exit(a);
	assign_index(a);
	if (a->size_a == 3)
		sort_3(a);
	else
		push_to_b(a, a->size_a / 2);
	//print_stack(a->stack_a, a->size_a);
	//print_stack(a->stack_b, a->size_b);
	print_instructions(a);
	free_memory_and_exit(a);
}