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
			a->stack_a[k] = ft_atoi(tmp[j]);
			a->stack_tmp[k] = ft_atoi(tmp[j]);
			j++;
			k++;
		}
		i++;
	}
	free_tmp(tmp);
}

void	allocate_memory(t_stack *a, char **argv, int size)
{
	a->size_a = size;
	a->size_tmp = size;
	a->size_b = 0;
	a->stack_a = (int *)malloc(sizeof(int) * a->size_a);
	a->stack_b = (int *)malloc(sizeof(int) * a->size_a);
	a->stack_tmp = (int *)malloc(sizeof(int) * a->size_a);
	if (a->stack_a == NULL || a->stack_b == NULL || a->stack_tmp == NULL)
		exit(EXIT_FAILURE);
	fill_stack(a, argv);
	check_duplicate(a);
}

void	free_memory_and_exit(t_stack *a, int status)
{
	free(a->stack_a);
	free(a->stack_b);
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