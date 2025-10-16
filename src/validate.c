/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 03:59:32 by yzhang2           #+#    #+#             */
/*   Updated: 2025/10/10 05:19:01 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	not_num(char *str)
{
	if (!(str[0] == '+' || str[0] == '-' || (str[0] >= '0' && str[0] <= '9')))
		return (1);
	if ((str[0] == '+' || str[0] == '-') && (!(str[0] >= '0' && str[0] <= '9')))
		return (1);
	while (*++str)
	{
		if (!(str[0] >= '0' && str[0] <= '9'))
			return (1);
	}
	return (0);
}

int	if_dup(t_node *s, int i)
{
	if (!s)
		return (0);
	while (s)
	{
		if (s->value == i)
			return (1);
		s = s->next;
	}
	return (0);
}
