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

static void get_target(t_stack *a)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (a->stack_b[i])
    {
        j = 0;
        tmp = 2147483647;
        while (j < a->size_a)
        {
            if (a->stack_a[j] > a->stack_b[i] && a->stack_a[j] < tmp)
            {
                a->b_target[i] = j;
                tmp = a->stack_a[j];
            }
            j++;
        }
        if (tmp == 2147483647)
            a->b_target[i] = find_min_index(a);
        i++;
    }
}

static void get_cost(t_stack *a)
{
    int i;

    i = 0;
    while (i < a->size_b)
    {
        a->cost_b[i] = i;
        if (a->cost_b[i] > a->size_b / 2)
            a->cost_b[i] = (a->size_b - a->cost_b[i]) * -1;
        a->cost_a[i] = a->b_target[i];
        if (a->cost_a[i] > a->size_a / 2)
            a->cost_a[i] = (a->size_a - a->cost_a[i]) * -1;
        i++;
    }
}

static void rotate_and_push(t_stack *a, int cost_a, int cost_b)
{
    int i;

    i = 0;
    if (cost_b < 0)
    {
        while (i++ < cost_b * -1)
            rrb(a);
    }
    else if (cost_b >= 0)
    {
        while (i++ < cost_b)
            rb(a);
    }
    i = 0;
    if (cost_a < 0)
    {
        while (i++ < cost_a * -1)
            rra(a);
    }
    else if (cost_a >= 0)
    {
        while (i++ < cost_a)
            ra(a);
    }
    pa(a);
}

static void move_cheapest(t_stack *a)
{
    int i;
    int cheapest;
    int cost_a;
    int cost_b;

    i = 0;
    cheapest = 2147483647;
    while (i < a->size_b)
    {
        if (abs(a->cost_a[i]) + abs(a->cost_b[i]) < cheapest)
        {
            cheapest = abs(a->cost_a[i]) + abs(a->cost_b[i]);
            cost_a = a->cost_a[i];
            cost_b = a->cost_b[i];
        }
        i++;
    }
    rotate_and_push(a, cost_a, cost_b);
}

void    solve(t_stack *a)
{
    while (a->size_b > 0)
    {
        get_target(a);
        get_cost(a);
        move_cheapest(a);
    }
    if (a->size_a / 2 > find_min_index(a))
    {
        while (a->stack_a[0] != find_min(a))
            ra(a);
    }
    else
    {
        while (a->stack_a[0] != find_min(a))
            rra(a);
    }
}

void    sort(t_stack *a)
{
    if (a->size_a == 2 && check_if_sorted(a) != 1)
		sa(a);
	else if (a->size_a == 3)
		sort_3(a);
    else
    {
        while (a->size_a > 3)
            pb(a);
        sort_3(a);
        solve(a);
    }
}