/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 05:02:06 by yzhang2           #+#    #+#             */
/*   Updated: 2025/10/14 04:16:54 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr_prepare(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rr(a, b, false);
	prepare_index(*a);
	prepare_index(*b);
}

static void	rrr_prepare(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rrr(a, b, false);
	prepare_index(*a);
	prepare_index(*b);
}

static void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->up_down && cheapest_node->target->up_down)
		rr_prepare(a, b, cheapest_node);
	else if (!(cheapest_node->up_down) && !(cheapest_node->target->up_down))
		rrr_prepare(a, b, cheapest_node);
	to_the_top(a, cheapest_node, 'a');
	to_the_top(b, cheapest_node->target, 'b');
	pb(b, a, false);
}

static void	min_on_top(t_node **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->up_down)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		prepare_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		prepare_nodes_b(*a, *b);
		to_the_top(a, (*b)->target, 'a');
		pa(a, b, false);
	}
	prepare_index(*a);
	min_on_top(a);
}
