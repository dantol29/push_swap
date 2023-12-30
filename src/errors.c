#include "../includes/push_swap.h"

void	check_argv(int argc, char **numbers)
{
	int	j;
    int i;

    i = 0;
    if (argc > 2)
    {
        i = 1;
    }
	while (numbers[i])
	{
        j = 0;
        while (numbers[i][j])
        {
            if (!((numbers[i][j] >= '0' && numbers[i][j] <= '9') || numbers[i][j] == '-'))
		    {
			    ft_putstr_fd("Error\n", 2);
			    exit(EXIT_FAILURE);
		    }
		    j++;
        }
        i++;
	}
}

void    check_duplicates(int argc, char **numbers)
{
    int i;
    int j;
    int num;

    i = 0;
    if (argc > 2)
        i = 1;
    while (numbers[i])
    {
        num = ft_atoi(numbers[i]);
        j = 0;
        if (argc > 2)
            j = 1;
        while (numbers[j])
        {
            if (num == ft_atoi(numbers[j]) && i != j)
            {
                ft_putstr_fd("Error\n", 2);
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