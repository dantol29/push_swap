#include "../includes/push_swap.h"

static void	fill_stack(t_stack *a, char **numbers, int j)
{
	int	i;

	i = 0;
	while (i < a->size_a)
	{
		a->stack_a[i] = ft_atoi(numbers[j]);
		j++;
		i++;
	}
}

void	allocate_memory(t_stack *a, char **argv, int argc)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (argc > 2)
		i = argc - 1;
	a->size_a = i;
	a->size_b = 0;
	a->stack_a = (int *)malloc(sizeof(int) * a->size_a);
	a->stack_b = (int *)malloc(sizeof(int) * a->size_a);
	a->stack_tmp = (int *)malloc(sizeof(int) * a->size_a);
	a->b_target = (int *)malloc(sizeof(int) * a->size_a);
	a->cost_a = (int *)malloc(sizeof(int) * a->size_a);
	a->cost_b = (int *)malloc(sizeof(int) * a->size_a);
	if (a->stack_b == NULL || a->stack_a == NULL || a->stack_tmp == NULL\
	|| a->b_target == NULL || a->cost_a == NULL || a->cost_b == NULL)
		exit(EXIT_FAILURE);
	if (argc > 2)
		fill_stack(a, argv, 1);
	else
		fill_stack(a, argv, 0);
}

void	free_memory_and_exit(t_stack *a)
{
	free(a->stack_a);
	free(a->stack_b);
	free(a->stack_tmp);
	free(a->b_target);
	free(a->cost_a);
	free(a->cost_b);
	free(a);
	exit(EXIT_SUCCESS);
}