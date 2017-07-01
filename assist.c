/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:08:42 by lkomarov          #+#    #+#             */
/*   Updated: 2016/12/08 12:19:25 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_stack(t_stack *stack)
{
	int		i;

	i = stack->top;
	ft_putstr("top->[");
	while (i >= 0)
	{
		ft_putnbr(stack->data[i]);
		ft_putchar(' ');
		i--;
	}
	ft_putstr("]<-bottom\n");
}

t_stack		*newstack(int argc)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (new_stack)
	{
		new_stack->data = (int *)malloc(sizeof(int) * (argc + 1));
		new_stack->top = -1;
		new_stack->min = 0;
		new_stack->max = 0;
		new_stack->score = (t_score *)malloc(sizeof(t_score) * (argc + 1));
	}
	while (argc + 1 > 0)
	{
		new_stack->data[argc] = 0;
		new_stack->score[argc].result = 0;
		argc--;
	}
	return (new_stack);
}

int			find_index(t_stack *s, int n, int flag)
{
	int		i;
	int		ind;
	int		temp;

	ind = 0;
	i = 0;
	while (i <= s->top)
	{
		temp = s->score[i].result;
		flag == 0 ? temp = s->data[i] : temp;
		if (n == temp)
		{
			ind = i;
			break ;
		}
		i++;
	}
	return (ind);
}

int			if_neg(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void		reset_min_max(t_stack *stack)
{
	find_max(stack);
	find_min(stack);
}
