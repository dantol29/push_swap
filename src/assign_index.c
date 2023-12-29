#include "../includes/push_swap.h"

int	find_next_min(t_stack *a, int *used_index, int size)
{
	int	i;
	int	min;
	int	status;
	int	tmp;

	tmp = size;
	i = 0;
	min = 2147483647;
	while (i < a->size_a)
	{
		status = 0;
		size = tmp;
		if (a->stack_a[i] < min)
		{
			while (size > 0)
			{
				if (used_index[size - 1] == i)
					status = 1;
				size--;
			}
			if (status != 1)
				min = a->stack_a[i];
		}
		i++;
	}
	i = 0;
	while (a->stack_a[i] != min)
		i++;
	return (i);
}

void	assign_index(t_stack *a)
{
	int	min;
	int	index;
	int	*used_index;

	ft_memcpy(a->stack_tmp, a->stack_a, a->size_a);
	used_index = ft_calloc(a->size_a, sizeof(int));
	index = 1;
	while(index < a->size_a)
	{
		min = find_next_min(a, used_index, index - 1);
		a->stack_tmp[min] = index;
		used_index[index - 1] = min;
		index++;
	};
	ft_memcpy(a->stack_a, a->stack_tmp, a->size_a);
	free(used_index);
}