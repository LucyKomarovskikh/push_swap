/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:08:42 by lkomarov          #+#    #+#             */
/*   Updated: 2016/12/08 12:19:25 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_r(t_stack *s, int i, int fl)
{
	int	count;

	count = if_neg(i);
	while (count > 0)
	{
		if (i < 0)
		{
			rrotate_stack(s);
			fl == 1 ? ft_putstr("rra\n") : ft_putstr("rrb\n");
		}
		else
		{
			rotate_stack(s);
			fl == 1 ? ft_putstr("ra\n") : ft_putstr("rb\n");
		}
		count--;
	}
}

void	perform_rab(t_stack *a, t_stack *b, int i)
{
	int	count;

	count = if_neg(i);
	while (count > 0)
	{
		if (i < 0)
		{
			rrotate_stack(a);
			rrotate_stack(b);
			ft_putstr("rrr\n");
		}
		else
		{
			rotate_stack(a);
			rotate_stack(b);
			ft_putstr("rr\n");
		}
		count--;
	}
	push_a(a, b);
	ft_putstr("pa\n");
	reset_min_max(a);
	reset_min_max(b);
}

void	perform(t_stack *a, t_stack *b, int pos)
{
	perform_r(a, b->score[pos].r_a, 1);
	perform_r(b, b->score[pos].r_b, 0);
	perform_rab(a, b, b->score[pos].r_ab);
}

void	final_rotation(t_stack *a)
{
	int	result;

	result = find_index(a, a->min, 0);
	if (result >= a->top / 2)
		perform_r(a, (a->top - result), 1);
	else
		perform_r(a, -(result + 1), 1);
}
