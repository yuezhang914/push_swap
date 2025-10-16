/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:01:11 by yzhang2           #+#    #+#             */
/*   Updated: 2025/10/14 05:05:30 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	bool			up_down;
	bool			cheapest;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
}					t_node;

int					not_num(char *str);
int					if_dup(t_node *s, int i);

void				free_stack(t_node **s);
void				handle_error(t_node **s);
void				free_split_result(char **arr);

int					safe_parse_int(const char *s, int *out);

void				sa(t_node **a, bool print);
void				sb(t_node **b, bool print);
void				ss(t_node **a, t_node **b, bool print);

void				pa(t_node **a, t_node **b, bool print);
void				pb(t_node **b, t_node **a, bool print);

void				ra(t_node **a, bool print);
void				rb(t_node **b, bool print);
void				rr(t_node **a, t_node **b, bool print);

void				rra(t_node **a, bool print);
void				rrb(t_node **b, bool print);
void				rrr(t_node **a, t_node **b, bool print);

int					stack_len(t_node *stack);
t_node				*find_last(t_node *stack);
t_node				*find_min(t_node *stack);
t_node				*find_max(t_node *stack);
t_node				*find_cheapest(t_node *node);

void				sort_three(t_node **a);
bool				is_sorted(t_node *stack);

int					init_a(t_node **a, char **values);

void				prepare_index(t_node *stack);
void				prepare_cheapest(t_node *stack);
void				prepare_nodes_a(t_node *a, t_node *b);
void				prepare_nodes_b(t_node *a, t_node *b);
void				to_the_top(t_node **stack, t_node *top_node,
						char stack_name);

void				sort(t_node **a, t_node **b);

#endif