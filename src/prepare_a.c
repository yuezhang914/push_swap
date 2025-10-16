/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 02:55:13 by yzhang2           #+#    #+#             */
/*   Updated: 2025/10/14 04:15:59 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_index(t_node *stack)
{
	int	i;
	int	half;

	if (!stack)
		return ;
	i = 0;
	half = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= half)
			stack->up_down = true;
		else
			stack->up_down = false;
		stack = stack->next;
		i++;
	}
}

static void	find_a_target_in_b(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target_in_b;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_in_b = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_in_b;
		a = a->next;
	}
}

static void	cost_a(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->up_down))
			a->cost = len_a - (a->index);
		if (a->target->up_down)
			a->cost += a->target->index;
		else
			a->cost += len_b - (a->target->index);
		a = a->next;
	}
}

void	prepare_cheapest(t_node *stack)
{
	long	cheapest_cost;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_cost)
		{
			cheapest_cost = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	prepare_nodes_a(t_node *a, t_node *b)
{
	prepare_index(a);
	prepare_index(b);
	find_a_target_in_b(a, b);
	cost_a(a, b);
	prepare_cheapest(a);
}
