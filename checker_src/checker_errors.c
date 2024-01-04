/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:18:55 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/01/04 09:23:05 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	check_part(char **numbers, int j)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (numbers[j][i] != '\0')
	{
		if (numbers[j][i] >= '0' && numbers[j][i] <= '9')
		{
			while (numbers[j][i] >= '0' && \
			numbers[j][i] <= '9' && numbers[j][i + 1])
				i++;
			size += 1;
		}
		else if (!(numbers[j][i] == '-' \
		|| numbers[j][i] == '+' || numbers[j][i] == ' '))
		{
			ft_putstr_fd("Error\n", 2);
			free_tmp(numbers);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (size);
}

static int	check_errors(char *numbers)
{
	char	**tmp;
	int		size;
	int		i;

	size = 0;
	i = 0;
	tmp = ft_split(numbers, ' ');
	if (tmp[i] == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		free_tmp(tmp);
		exit(EXIT_FAILURE);
	}
	while (tmp[i])
	{
		size += check_part(tmp, i);
		i++;
	}
	free_tmp(tmp);
	return (size);
}

int	check_argv(char **numbers, int argc)
{
	int	i;
	int	size;

	if (argc == 1)
		exit(EXIT_FAILURE);
	i = 1;
	size = 0;
	while (numbers[i])
	{
		size += check_errors(numbers[i]);
		i++;
	}
	return (size);
}

void	check_duplicate(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size_a)
	{
		j = 0;
		while (j < a->size_a)
		{
			if (a->stack_a[i] == a->stack_a[j] && i != j)
			{
				ft_putstr_fd("Error\n", 2);
				free_memory_and_exit(a, 1);
			}
			j++;
		}
		i++;
	}
}

void	check_int(t_stack *a, char **tmp)
{
	int	i;
	int	j;

	i = 0;
	while (tmp[i])
	{
		j = ft_atoi(tmp[i]);
		if (j == 0)
		{
			if (!(tmp[i][0] == '0' && tmp[i][1] == '\0'))
			{
				ft_putstr_fd("Error\n", 2);
				free_tmp(tmp);
				free_memory_and_exit(a, 1);
			}
		}
		i++;
	}
}
