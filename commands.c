/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:08:42 by lkomarov          #+#    #+#             */
/*   Updated: 2016/12/08 12:19:25 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack *stack)
{
	int	temp;
	int	i;

	i = stack->top;
	temp = stack->data[stack->top];
	while (stack->top > 0)
	{
		stack->data[stack->top] = stack->data[stack->top - 1];
		stack->top--;
	}
	stack->data[0] = temp;
	stack->top = i;
}

void	rrotate_stack(t_stack *stack)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack->data[i];
	while (i < stack->top)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->top] = temp;
}

void	push_a(t_stack *a, t_stack *b)
{
	if (b->top == -1)
		return ;
	stack_push(a, stack_pop(b));
}

void	push_b(t_stack *a, t_stack *b)
{
	if (a->top == -1)
		return ;
	stack_push(b, stack_pop(a));
}

void	double_rotate_swp(t_stack *a, t_stack *b, int fl)
{
	if (fl == 0)
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	else if (fl == 1)
	{
		rrotate_stack(a);
		rrotate_stack(b);
	}
	else if (fl == 2)
	{
		swap_stack(a);
		swap_stack(b);
	}
}
