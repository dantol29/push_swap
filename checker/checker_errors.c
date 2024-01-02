#include "../includes/checker.h"

// static void check_int(char *str)
// {
//     if ((ft_atoi(str) == 0 && str[0] != '0') || str[0] == '\0')
//     {
//         if (ft_strcmp("-2147483648", str) == 0)
//             return ;
//         ft_putstr_fd("Error\n", 1);
// 		exit(EXIT_FAILURE);
//     }
//     if (ft_strlen(str) > 11 || (ft_strlen(str) > 10 && str[0] != '-'))
//     {
//         ft_putstr_fd("Error\n", 1);
// 		exit(EXIT_FAILURE);
//     }
// }

static int check_part(char **numbers, int j)
{
    int i;
    int size;

    i = 0;
    size = 0;
    while (numbers[j][i] != '\0')
    {
        if (numbers[j][i] >= '0' && numbers[j][i] <= '9')
        {
            while (numbers[j][i] >= '0' && numbers[j][i] <= '9' && numbers[j][i + 1])
                i++;
            size += 1;
        }
        else if (!(numbers[j][i] == '-' || numbers[j][i] == '+' || numbers[j][i] == ' '))
        {
            ft_putstr_fd("Error\n", 1);
            free_tmp(numbers);
        }
        i++;
    }
    return (size);
}

static int check_errors(char *numbers)
{
    char **tmp;
    int size;
    int i;

    size = 0;
    i = 0;
    tmp = ft_split(numbers, ' ');
    while (tmp[i])
    {
        size += check_part(tmp, i);
        i++;
    }
    free_tmp(tmp);
    return (size);
}

int check_argv(char **numbers)
{
    int i;
    int size;

    i = 1;
    size = 0;
	while (numbers[i])
	{
        size += check_errors(numbers[i]);
        i++;
	}
    return (size);
}
