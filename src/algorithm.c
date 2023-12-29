#include "../includes/push_swap.h"

void    shift_stack(t_stack *a)
{
    if (a->size_a / 2 > find_min_index(a))
    {
        while (a->stack_a[0] != find_min(a))
        {
            ra(a);
            printf("ra\n");
        }
    }
    else
    {
        while (a->stack_a[0] != find_min(a))
        {
            rra(a);
            printf("rra\n");
        }
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
    shift_stack(a);
}