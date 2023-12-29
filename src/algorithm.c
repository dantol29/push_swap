#include "../includes/push_swap.h"

void	sort_3(t_stack *a)
{
	if (a->stack_a[0] > a->stack_a[1] && a->stack_a[1] > a->stack_a[2])
	{
		sa(a);
		rra(a);
	}
	if (a->stack_a[0] > a->stack_a[1] && a->stack_a[0] < a->stack_a[2])
		sa(a);
	if (a->stack_a[0] > a->stack_a[1] && a->stack_a[1] < a->stack_a[2])
		ra(a);
	if (a->stack_a[0] < a->stack_a[1] && a->stack_a[1] > a->stack_a[2] && a->stack_a[0] > a->stack_a[2])
		rra(a);
	if (a->stack_a[0] < a->stack_a[1] && a->stack_a[1] > a->stack_a[2])
	{
		sa(a);
		ra(a);
	}
}

static void decide_to_rotate(t_stack *a, int hold_first, int hold_second)
{
	int	i;

	i = 0;
	if (a->size_a - hold_second > hold_first)
	{
		while (i < hold_first)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < a->size_a - hold_second)
		{
			rra(a);
			i++;
		}
	}
}

static void	find_holds(t_stack *a, int *hold_first, int *hold_second, int chunk_size)
{
	int	i;

	i = 0;
	while (i < a->size_a)
	{
		if (a->stack_a[i] > chunk_size - chunk_size && a->stack_a[i] <= chunk_size)
		{
			*hold_first = i;
			break ;
		}
		i++;
	}
	i = 0;
	while (i < a->size_a)
	{
		if (a->stack_a[a->size_a - i - 1] > chunk_size - chunk_size && a->stack_a[a->size_a - i - 1] <= chunk_size)
		{
			*hold_second = a->size_a - i - 1;
			break ;
		}
		i++;
	}
}

static void	push_to_a(t_stack *a)
{
	int	i;
	int	max;

	//print_stack(a->stack_b, a->size_b);
	while (a->size_b > 0)
	{
		max = find_max_index(a);
		//printf("%d max\n", a->stack_b[max]);
		i = 0;
		if (a->size_b / 2 > max)
		{
			while (i++ < max)
				rb(a);
		}
		else
		{
			while (i++ < a->size_b - max)
				rrb(a);
		}
		//printf("%d push\n", a->stack_b[0]);
		pa(a);
	}
}

int	push_to_b(t_stack *a, int chunk_size)
{
	int	hold_first;
	int	hold_second;
	int	i;
	int	tmp;

	hold_first = 0;
	hold_second = 0;
	tmp = chunk_size;
	while (a->size_a > 0)
	{
		i = 0;
		//printf("%d chunk\n", chunk_size);
		while (i < a->size_a)
		{
			find_holds(a, &hold_first, &hold_second, chunk_size);
			//printf("%d first %d second\n", hold_first, hold_second);
			decide_to_rotate(a, hold_first, hold_second);
			check_biggest(a, a->stack_a[0]);
			pb(a);
			i++;
		}
		chunk_size += tmp;
	}
	push_to_a(a);
	return (0);
}