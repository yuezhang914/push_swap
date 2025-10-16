/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 02:33:39 by yzhang2           #+#    #+#             */
/*   Updated: 2025/10/14 04:59:04 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_three(t_node **a)
{
	t_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

static void	handle_sorting(t_node **a, t_node **b)
{
	int	len;

	len = stack_len(*a);
	if (len == 2)
	{
		sa(a, false);
		return ;
	}
	if (len == 3)
	{
		sort_three(a);
		return ;
	}
	sort(a, b);
}

static int	init_from_single_arg(t_node **a, char *arg, char ***tokens_out)
{
	char	**tmp;
	int		ret;

	tmp = NULL;
	ret = 0;
	tmp = ft_split(arg, ' ');
	if (!tmp)
		handle_error(a);
	ret = init_a(a, tmp);
	if (ret == -1)
	{
		if (tmp)
			free_split_result(tmp);
		handle_error(a);
	}
	*tokens_out = tmp;
	return (0);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	**tokens;

	a = NULL;
	b = NULL;
	tokens = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
		init_from_single_arg(&a, av[1], &tokens);
	else
	{
		if (init_a(&a, av + 1) == -1)
			handle_error(&a);
	}
	if (!is_sorted(a))
		handle_sorting(&a, &b);
	if (tokens)
		free_split_result(tokens);
	free_stack(&a);
	return (0);
}
