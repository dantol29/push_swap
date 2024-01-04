/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:23:33 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/01/04 09:59:44 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
			a->stack_tmp[k] = ft_atoi(tmp[j]);
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
	a->size_tmp = size;
	a->size_b = 0;
	a->stack_a = ft_calloc(a->size_a, sizeof(int));
	a->stack_b = ft_calloc(a->size_a, sizeof(int));
	a->stack_tmp = ft_calloc(a->size_a, sizeof(int));
	if (a->stack_a == NULL || a->stack_b == NULL || a->stack_tmp == NULL)
		exit(EXIT_FAILURE);
	fill_stack(a, argv);
	check_duplicate(a);
}

void	free_memory_and_exit(t_stack *a, int status)
{
	free(a->stack_a);
	free(a->stack_b);
	free(a->stack_tmp);
	free(a);
	if (status == 1)
		exit(EXIT_FAILURE);
	ft_putstr_fd("OK\n", 1);
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

int	check_command(char *input)
{
	if (ft_strcmp(input, "ra\n") == 0)
		return (0);
	else if (ft_strcmp(input, "rb\n") == 0)
		return (0);
	else if (ft_strcmp(input, "rra\n") == 0)
		return (0);
	else if (ft_strcmp(input, "rrb\n") == 0)
		return (0);
	else if (ft_strcmp(input, "rr\n") == 0)
		return (0);
	else if (ft_strcmp(input, "rrr\n") == 0)
		return (0);
	else if (ft_strcmp(input, "sa\n") == 0)
		return (0);
	else if (ft_strcmp(input, "sb\n") == 0)
		return (0);
	else if (ft_strcmp(input, "pa\n") == 0)
		return (0);
	else if (ft_strcmp(input, "pb\n") == 0)
		return (0);
	else
		return (1);
}
