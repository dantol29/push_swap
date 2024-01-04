/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:46:34 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/01/04 09:47:03 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack *a, int cost_a)
{
	while (cost_a < 0)
	{
		rra(a);
		ft_putstr_fd("rra\n", 1);
		cost_a++;
	}
	while (cost_a > 0)
	{
		ra(a);
		ft_putstr_fd("ra\n", 1);
		cost_a--;
	}
}

void	rotate_b(t_stack *a, int cost_b)
{
	while (cost_b < 0)
	{
		rrb(a);
		ft_putstr_fd("rrb\n", 1);
		cost_b++;
	}
	while (cost_b > 0)
	{
		rb(a);
		ft_putstr_fd("rb\n", 1);
		cost_b--;
	}
}

void	rotate_and_push(t_stack *a, int cost_a, int cost_b)
{
	while (cost_b < 0 && cost_a < 0)
	{
		rra(a);
		rrb(a);
		ft_putstr_fd("rrr\n", 1);
		cost_a++;
		cost_b++;
	}
	while (cost_b > 0 && cost_a > 0)
	{
		ra(a);
		rb(a);
		ft_putstr_fd("rr\n", 1);
		cost_a--;
		cost_b--;
	}
	if (cost_a < 0 || cost_a > 0)
		rotate_a(a, cost_a);
	if (cost_b < 0 || cost_b > 0)
		rotate_b(a, cost_b);
	pa(a);
}
