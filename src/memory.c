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
		exit(EXIT_FAILURE);
	a->stack_tmp = (int *)malloc(sizeof(int) * a->size_a);
	if (a->stack_tmp == NULL)
		exit(EXIT_FAILURE);
	a->b_target = (int *)malloc(sizeof(int) * a->size_a);
	if (a->b_target == 	NULL)
		exit(EXIT_FAILURE);
	a->cost_a = (int *)malloc(sizeof(int) * a->size_a);
	if (a->cost_a == 	NULL)
		exit(EXIT_FAILURE);
	a->cost_b = (int *)malloc(sizeof(int) * a->size_a);
	if (a->cost_b == NULL)
		exit(EXIT_FAILURE);
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