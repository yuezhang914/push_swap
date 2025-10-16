/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 02:55:22 by yzhang2           #+#    #+#             */
/*   Updated: 2025/10/14 04:08:24 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_b_target_in_a(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target_in_a;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_in_a = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_in_a;
		b = b->next;
	}
}

void	prepare_nodes_b(t_node *a, t_node *b)
{
	prepare_index(a);
	prepare_index(b);
	find_b_target_in_a(a, b);
}

void	to_the_top(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->up_down)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->up_down)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
