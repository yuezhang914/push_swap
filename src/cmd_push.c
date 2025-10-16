/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 02:12:22 by yzhang2           #+#    #+#             */
/*   Updated: 2025/10/13 03:45:53 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **dst, t_node **src)
{
	t_node	*node_to_move;
	t_node	*old_src_head;

	if (!src || !*src)
		return ;
	old_src_head = *src;
	node_to_move = old_src_head;
	*src = old_src_head->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_move->prev = NULL;
	if (!dst || !*dst)
	{
		node_to_move->next = NULL;
		if (dst)
			*dst = node_to_move;
	}
	else
	{
		node_to_move->next = *dst;
		(*dst)->prev = node_to_move;
		*dst = node_to_move;
	}
}

void	pa(t_node **a, t_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_node **b, t_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
