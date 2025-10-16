/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 03:33:22 by yzhang2           #+#    #+#             */
/*   Updated: 2025/10/13 20:05:49 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_node **stack)
{
	t_node	*tail;
	t_node	*before_tail;
	t_node	*old_head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tail = find_last(*stack);
	before_tail = tail->prev;
	before_tail->next = NULL;
	old_head = *stack;
	tail->prev = NULL;
	tail->next = old_head;
	old_head->prev = tail;
	*stack = tail;
}

void	rra(t_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
