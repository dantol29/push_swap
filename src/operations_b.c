
#include "../includes/push_swap.h"

void	pb(t_stack *a)
{
	int	i;

	i = a->size_b;
	while (i > 0)
	{
		a->stack_b[i] = a->stack_b[i - 1];
		i--;
	}
	a->stack_b[0] = a->stack_a[0];
	i = 0;
	while (i < a->size_a - 1)
	{
		a->stack_a[i] = a->stack_a[i + 1];
		i++;
	}
	a->size_a--;
	a->size_b++;
	ft_putstr_fd("pb\n", 1);
}

void	rb(t_stack *a)
{
	int	temp;
	int	i;

	i = 0;
	temp = a->stack_b[0];
	while (i < a->size_b - 1)
	{
		a->stack_b[i] = a->stack_b[i + 1];
		i++;
	}
	a->stack_b[a->size_b - 1] = temp;
}

void	rrb(t_stack *a)
{
	int	temp;
	int	i;

	i = 0;
	temp = a->stack_b[a->size_b - 1];
	i = a->size_b - 1;
	while (i > 0)
	{
		a->stack_b[i] = a->stack_b[i - 1];
		i--;
	}
	a->stack_b[0] = temp;
}