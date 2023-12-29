#include "../includes/push_swap.h"

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

void	allocate_memory(t_stack *a, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	a->size_a = i;
	a->size_b = 0;
	a->stack_a = (int *)malloc(sizeof(int) * a->size_a);
	if (a->stack_a == NULL)
		exit(EXIT_FAILURE);
	a->stack_b = (int *)malloc(sizeof(int) * a->size_a);
	if (a->stack_b == NULL)
	{
		free(a->stack_a);
		exit(EXIT_FAILURE);
	}
	a->stack_tmp = (int *)malloc(sizeof(int) * a->size_a);
	if (a->stack_tmp == NULL)
	{
		free(a->stack_a);
		free(a->stack_b);
		exit(EXIT_FAILURE);
	}
	a->instructions = (char **)malloc(sizeof(char *) * (a->size_a * 100));
	if (a->stack_tmp == NULL)
	{
		free(a->stack_a);
		free(a->stack_b);
		free(a->stack_tmp);
		exit(EXIT_FAILURE);
	}
	i = 0;
	a->instructions_size = 0;
	while (a->instructions[i])
	{
		a->instructions[i] = (char *)malloc(sizeof(char *) * 3);
		i++;
	}
	fill_stack(a, argv);
}

void	free_memory_and_exit(t_stack *a)
{
	free(a->stack_a);
	free(a->stack_b);
	free(a->stack_tmp);
	free(a);
	exit(EXIT_SUCCESS);
}