/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:08:42 by lkomarov          #+#    #+#             */
/*   Updated: 2016/12/08 12:19:25 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack *stack, int value)
{
	stack->top++;
	stack->data[stack->top] = value;
}

int		stack_pop(t_stack *stack)
{
	int	i;

	i = stack->data[stack->top];
	stack->top--;
	return (i);
}

void	swap_stack(t_stack *stack)
{
	int	temp;

	temp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = temp;
}

void	find_min(t_stack *s)
{
	int	i;

	i = s->top;
	if (i >= 0)
		s->min = s->data[i];
	while (i > 0)
	{
		s->data[i - 1] < s->min ? s->min = s->data[i - 1] : s->min;
		i--;
	}
}

void	find_max(t_stack *s)
{
	int	i;

	i = s->top;
	if (i >= 0)
		s->max = s->data[i];
	while (i > 0)
	{
		s->data[i - 1] > s->max ? s->max = s->data[i - 1] : s->max;
		i--;
	}
}
