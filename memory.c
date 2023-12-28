#include "push_swap.h"

void	fill_stack(t_stack *a, char **numbers)
{
	int	i;

	i = 0;
	while (i < a->size_a)
	{
		a->stack_a[i] = ft_atoi(numbers[i]);
		i++;
	}
}

static int	count_numbers(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] != ' ' && str[i])
		{
			count++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
	return (count);
}

int	allocate_memory(t_stack *a, char **argv)
{
	a->size_a = count_numbers(argv[1]);
	a->size_b = 0;
	a->stack_a = (int *)malloc(sizeof(int) * a->size_a);
	if (a->stack_a == NULL)
		return (1);
	a->stack_b = (int *)malloc(sizeof(int) * a->size_a);
	if (a->stack_b == NULL)
	{
		free(a->stack_a);
		return (1);
	}
	a->stack_tmp = (int *)malloc(sizeof(int) * a->size_a);
	if (a->stack_tmp == NULL)
	{
		free(a->stack_a);
		free(a->stack_b);
		return (1);
	}
	return (0);
}

void	free_memory(t_stack *a)
{
	free(a->stack_a);
	free(a->stack_b);
	free(a->stack_tmp);
	free(a);
}