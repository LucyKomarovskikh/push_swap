/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_score.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:08:42 by lkomarov          #+#    #+#             */
/*   Updated: 2016/12/08 12:19:25 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		a_rotation(int a_top, int a_ind, int b_top, int b_ind)
{
	int	r_a;
	int	r_b;

	r_b = 0;
	r_a = a_top - a_ind;
	b_top == 0 ? r_b : (r_b = b_top - b_ind);
	if (r_a >= r_b)
		r_a = r_a - r_b;
	else
		r_a = 0;
	return (r_a);
}

int		r_a_rotation(int a_ind, int b_top, int b_ind)
{
	int	r_a;
	int	r_b;

	r_b = 0;
	r_a = -(0 - a_ind) + 1;
	b_top == -1 ? r_b : (r_b = -(0 - b_ind) + 1);
	if (r_a >= r_b)
		r_a = r_a - r_b;
	else
		r_a = 0;
	return (-(r_a));
}

int		get_a_score(t_stack *a, t_stack *b, int a_ind, int b_ind)
{
	int	r_a;

	if ((a_ind > (a->top / 2) && b_ind == (b->top / 2))
			|| (a_ind == (a->top / 2) && b_ind > (b->top / 2))
			|| (a_ind > (a->top / 2) && b_ind > (b->top / 2))
			|| (a_ind == (a->top / 2) && b_ind == (b->top / 2)))
		r_a = a_rotation(a->top, a_ind, b->top, b_ind);
	if ((a_ind == (a->top / 2) && b_ind < (b->top / 2))
			|| (a_ind < (a->top / 2) && b_ind == (b->top / 2))
			|| (a_ind < (a->top / 2) && b_ind < (b->top / 2)))
		r_a = r_a_rotation(a_ind, b->top, b_ind);
	if (a_ind > (a->top / 2) && b_ind < (b->top / 2))
		r_a = a_rotation(a->top, a_ind, 0, b_ind);
	if (a_ind < (a->top / 2) && b_ind > (b->top / 2))
		r_a = r_a_rotation(a_ind, -1, b_ind);
	b->score[b_ind].r_a = r_a;
	return (if_neg(r_a));
}
