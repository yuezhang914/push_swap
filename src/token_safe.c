/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_safe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 05:36:41 by yzhang2           #+#    #+#             */
/*   Updated: 2025/10/13 01:32:40 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*skip_spaces(const char *s)
{
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'
		|| *s == '\v')
		s++;
	return (s);
}

static int	get_sign_and_advance(const char **ps)
{
	int	sign;

	sign = 1;
	if (**ps == '+' || **ps == '-')
	{
		if (**ps == '-')
			sign = -1;
		(*ps)++;
	}
	return (sign);
}

static int	accumulate_digits(const char **ps, long long limit,
		long long *val_out)
{
	long long	val;
	int			digit;

	val = 0;
	if (!ft_isdigit((unsigned char)**ps))
		return (-1);
	while (ft_isdigit((unsigned char)**ps))
	{
		digit = **ps - '0';
		if (val > (limit - digit) / 10)
			return (-1);
		val = val * 10 + digit;
		(*ps)++;
	}
	*val_out = val;
	return (0);
}

static int	finalize_and_write(const char *p, int sign, long long val, int *out)
{
	while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r' || *p == '\f'
		|| *p == '\v')
		p++;
	if (*p != '\0')
		return (-1);
	if (sign == -1)
		*out = (int)(-val);
	else
		*out = (int)val;
	return (0);
}

int	safe_parse_int(const char *s, int *out)
{
	const char	*p;
	int			sign;
	long long	limit;
	long long	val;

	if (!s || !out)
		return (-1);
	p = skip_spaces(s);
	sign = get_sign_and_advance(&p);
	if (sign == 1)
		limit = (long long)INT_MAX;
	else
		limit = -(long long)INT_MIN;
	if (accumulate_digits(&p, limit, &val) != 0)
		return (-1);
	return (finalize_and_write(p, sign, val, out));
}
