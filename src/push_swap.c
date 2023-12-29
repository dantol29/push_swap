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
	sort(a);
	print_stack(a->stack_a, a->size_a);
	print_stack(a->stack_b, a->size_b);
	free_memory_and_exit(a);
}