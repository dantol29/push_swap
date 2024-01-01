#include "../includes/checker.h"

static void check_int(char *str)
{
    if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483647 ||\
    (ft_atoi(str) == 0 && str[0] != '0'))
    {
        if (ft_strcmp("-2147483648", str) == 0)
            return ;
        ft_putstr_fd("Error\n", 1);
		exit(EXIT_FAILURE);
    }
    if (ft_strlen(str) > 11 || (ft_strlen(str) > 10 && str[0] != '-'))
    {
        ft_putstr_fd("Error\n", 1);
		exit(EXIT_FAILURE);
    }
}

static void check_duplicates(int argc, char **numbers)
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
                ft_putstr_fd("Error\n", 1);
                exit(EXIT_FAILURE);
            }
            j++;
        }
        i++;
    }
}

void	check_argv(int argc, char **numbers)
{
    int i;

    i = 0;
    if (argc == 1)
        exit(EXIT_FAILURE);
    if (argc > 2)
    {
        i = 1;
    }
	while (numbers[i])
	{
        check_int(numbers[i]);
        i++;
	}
    check_duplicates(argc, numbers);
}

int	check_if_sorted(t_stack *a)
{
	ft_memcpy(a->stack_b, a->stack_tmp, a->size_tmp);
	quicksort(a->stack_b, a->size_a);
	if (ft_memcmp(a->stack_a, a->stack_b, a->size_tmp) != 0)
		return (1);
	return (0);
}