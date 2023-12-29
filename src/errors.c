#include "../includes/push_swap.h"

void	check_argv(int argc, char **argv)
{
	int	j;

	if (argc != 2)
		exit(EXIT_FAILURE);
	j = 0;
	while (argv[1][j])
	{
		if (!((argv[1][j] >= '0' && argv[1][j] <= '9') || argv[1][j] == '-' || argv[1][j] == ' '))
		{
			ft_putstr("Error\n");
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void    check_duplicates(char **numbers)
{
    int i;
    int j;
    int num;

    i = 0;
    while (numbers[i])
    {
        num = ft_atoi(numbers[i]);
        j = 0;
        while (numbers[j])
        {
            if (num == ft_atoi(numbers[j]) && i != j)
            {
                ft_putstr("Error\n");
                exit(EXIT_FAILURE);
            }
            j++;
        }
        i++;
    }
}

int	check_if_sorted(t_stack *a)
{
	ft_memcpy(a->stack_tmp, a->stack_a, a->size_a);
	quicksort(a->stack_tmp, a->size_a);
	if (ft_memcmp(a->stack_a, a->stack_tmp, a->size_a) == 0)
		return (1);
	return (0);
}