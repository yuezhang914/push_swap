/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 03:33:16 by yzhang2           #+#    #+#             */
/*   Updated: 2025/10/13 03:46:54 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*old_head;
	t_node	*new_head;
	t_node	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	old_head = *stack;
	new_head = old_head->next;
	new_head->prev = NULL;
	*stack = new_head;
	tail = find_last(new_head);
	tail->next = old_head;
	old_head->prev = tail;
	old_head->next = NULL;
}

void	ra(t_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
