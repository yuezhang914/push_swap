/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 02:53:28 by yzhang2           #+#    #+#             */
/*   Updated: 2025/10/14 04:08:24 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_node(t_node **stack, int value)
{
	t_node	*node;
	t_node	*last;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = value;
	node->index = 0;
	node->cost = 0;
	node->up_down = false;
	node->cheapest = false;
	node->target = NULL;
	node->next = NULL;
	if (!*stack)
	{
		node->prev = NULL;
		*stack = node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = node;
	node->prev = last;
}

int	init_a(t_node **a, char **values)
{
	int	i;
	int	val;

	if (!values)
		return (-1);
	i = 0;
	while (values[i])
	{
		if (safe_parse_int(values[i], &val))
			return (-1);
		if (if_dup(*a, val))
			return (-1);
		add_node(a, val);
		if (!(*a))
			return (-1);
		i++;
	}
	return (0);
}
