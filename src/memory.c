/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:52:20 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/01/04 11:12:33 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	fill_stack(t_stack *a, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	i = 1;
	k = 0;
	while (argv[i])
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j])
		{
			check_int(a, tmp);
			a->stack_a[k] = ft_atoi(tmp[j]);
			j++;
			k++;
		}
		free_tmp(tmp);
		i++;
	}
}

void	allocate_memory(t_stack *a, char **argv, int size)
{
	a->size_a = size;
	a->size_b = 0;
	a->stack_a = (int *)malloc(sizeof(int) * a->size_a);
	a->stack_b = (int *)malloc(sizeof(int) * a->size_a);
	a->stack_tmp = (int *)malloc(sizeof(int) * a->size_a);
	a->b_target = (int *)malloc(sizeof(int) * a->size_a);
	a->cost_a = (int *)malloc(sizeof(int) * a->size_a);
	a->cost_b = (int *)malloc(sizeof(int) * a->size_a);
	if (a->stack_b == NULL || a->stack_a == NULL || a->stack_tmp == NULL \
	|| a->b_target == NULL || a->cost_a == NULL || a->cost_b == NULL)
		exit(EXIT_FAILURE);
	fill_stack(a, argv);
	check_duplicate(a);
}

void	free_memory_and_exit(t_stack *a, int status)
{
	free(a->stack_a);
	free(a->stack_b);
	free(a->stack_tmp);
	free(a->b_target);
	free(a->cost_a);
	free(a->cost_b);
	free(a);
	if (status == 1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	free_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
