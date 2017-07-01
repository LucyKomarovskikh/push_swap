/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:08:42 by lkomarov          #+#    #+#             */
/*   Updated: 2016/12/08 12:19:25 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*s_normalize(t_stack *s)
{
	int		i;
	int		j;
	int		index;
	t_stack	*new_s;

	index = 0;
	i = 0;
	j = 0;
	new_s = newstack(s->top);
	while (i <= s->top)
	{
		while (j <= s->top)
		{
			if (s->data[i] > s->data[j])
				index++;
			j++;
		}
		stack_push(new_s, index);
		index = 0;
		j = 0;
		i++;
	}
	free_stack(s);
	return (new_s);
}

int			three_sorted(t_stack *a)
{
	int		i;

	i = 0;
	if (a->min == a->data[a->top] && a->max == a->data[0])
		return (1);
	while (i < a->top)
	{
		if (a->data[i] < a->data[i + 1])
		{
			if (a->data[i] == a->min && a->data[i + 1] == a->max)
				return (1);
		}
		i++;
	}
	return (0);
}

void		push_three(t_stack *a, t_stack *b)
{
	while (a->top > 2)
	{
		push_b(a, b);
		ft_putstr("pb\n");
	}
}

void		mini_sort_three(t_stack *a, t_stack *b)
{
	int		top;

	top = a->top;
	if (a->top > 2)
	{
		while (top != -1 && a->top > 2)
		{
			if (a->data[a->top] >= (a->max / 2))
			{
				push_b(a, b);
				ft_putstr("pb\n");
			}
			else
			{
				rotate_stack(a);
				ft_putstr("ra\n");
			}
			top--;
		}
	}
	push_three(a, b);
	reset_min_max(a);
	reset_min_max(b);
}

int			find_best_value(t_stack *s, int i)
{
	int		n;

	n = 0;
	if (i > s->max || i < s->min)
		return (s->min);
	else if (i < s->max && i > s->min)
	{
		if (i < s->data[s->top] && i > s->data[0])
			return (s->data[s->top]);
		else
		{
			while (n <= s->top)
			{
				if (s->data[n] > i && i > s->data[n + 1])
					return (s->data[n]);
				n++;
			}
		}
	}
	return (0);
}
