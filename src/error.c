/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 04:15:51 by yzhang2           #+#    #+#             */
/*   Updated: 2025/10/14 05:42:21 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **s)
{
	t_node	*tmp;
	t_node	*current;

	if (!s)
		return ;
	current = *s;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*s = NULL;
}

void	free_split_result(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	handle_error(t_node **s)
{
	free_stack(s);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}
