#include "../includes/checker.h"

static void	fill_stack(t_stack *a, char **numbers, int j)
{
	int	i;

	i = 0;
	while (i < a->size_a)
	{
		a->stack_a[i] = ft_atoi(numbers[j]);
		a->stack_tmp[i] = ft_atoi(numbers[j]);
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
	a->size_tmp = i;
	a->stack_a = (int *)malloc(sizeof(int) * a->size_a);
	a->stack_b = (int *)malloc(sizeof(int) * a->size_a);
	a->stack_tmp = (int *)malloc(sizeof(int) * a->size_a);
	if (a->stack_a == NULL || a->stack_b == NULL || a->stack_tmp == NULL)
		exit(EXIT_FAILURE);
	if (argc > 2)
		fill_stack(a, argv, 1);
	else
		fill_stack(a, argv, 0);
}

void	free_memory_and_exit(t_stack *a, char *line, int status)
{
	free(a->stack_a);
	free(a->stack_b);
	free(line);
	free(a);
	if (status == 1)
		exit(EXIT_FAILURE);
	ft_putstr_fd("OK\n", 1);
	exit(EXIT_SUCCESS);
}