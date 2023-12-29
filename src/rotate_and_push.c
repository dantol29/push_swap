#include "../includes/push_swap.h"

void    rotate_a(t_stack *a, int cost_a)
{
    while (cost_a < 0)
    {
        rra(a);
        printf("rra\n");
        cost_a++;
    }
    while (cost_a > 0)
    {
        ra(a);
        printf("ra\n");
        cost_a--;
    }
}

void    rotate_b(t_stack *a, int cost_b)
{
    while (cost_b < 0)
    {
        rrb(a);
        printf("rrb\n");
        cost_b++;
    }
    while (cost_b > 0)
    {
        rb(a);
        printf("rb\n");
        cost_b--;
    }
}

void    rotate_and_push(t_stack *a, int cost_a, int cost_b)
{
    while (cost_b < 0 && cost_a < 0)
    {
        rra(a);
        rrb(a);
        printf("rrr\n");
        cost_a++;
        cost_b++;
    }
    while (cost_b > 0 && cost_a > 0)
    {
        ra(a);
        rb(a);
        printf("rr\n");
        cost_a--;
        cost_b--;
    }
    if (cost_a < 0 || cost_a > 0)
        rotate_a(a, cost_a);
    if (cost_b < 0 || cost_b > 0)
        rotate_b(a, cost_b);
    pa(a);
}