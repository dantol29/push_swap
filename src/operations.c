
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
	a->instructions[a->instructions_size] = "pb";
	a->instructions_size++;
	//printf("pb\n");
}

void	pa(t_stack *a)
{
	int	i;

	i = a->size_a;
	while (i > 0)
	{
		a->stack_a[i] = a->stack_a[i - 1];
		i--;
	}
	a->stack_a[0] = a->stack_b[0];
	i = 0;
	while (i < a->size_b - 1)
	{
		a->stack_b[i] = a->stack_b[i + 1];
		i++;
	}
	a->size_b--;
	a->size_a++;
	a->instructions[a->instructions_size] = "pa";
	a->instructions_size++;
	//printf("pa\n");
}

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	i = 0;
	temp = a->stack_a[0];
	while (i < a->size_a - 1)
	{
		a->stack_a[i] = a->stack_a[i + 1];
		i++;
	}
	a->stack_a[a->size_a - 1] = temp;
	a->instructions[a->instructions_size] = "ra";
	a->instructions_size++;
	//printf("ra\n");
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
	a->instructions[a->instructions_size] = "rb";
	a->instructions_size++;
	//printf("rb\n");
}

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	i = 0;
	temp = a->stack_a[a->size_a - 1];
	i = a->size_a - 1;
	while (i > 0)
	{
		a->stack_a[i] = a->stack_a[i - 1];
		i--;
	}
	a->stack_a[0] = temp;
	a->instructions[a->instructions_size] = "rra";
	a->instructions_size++;
	//printf("rra\n");
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
	a->instructions[a->instructions_size] = "rrb";
	a->instructions_size++;
	//printf("rrb\n");
}

void	sa(t_stack *a)
{
	int temp;

	temp = a->stack_a[1];
	a->stack_a[1] = a->stack_a[0];
	a->stack_a[0] = temp;
	a->instructions[a->instructions_size] = "sa";
	a->instructions_size++;
	//printf("sa\n");
}