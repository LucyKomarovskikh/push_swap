/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_score.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:08:42 by lkomarov          #+#    #+#             */
/*   Updated: 2016/12/08 12:19:25 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		b_rotation(int a_top, int a_ind, int b_top, int b_ind)
{
	int	r_a;
	int	r_b;

	r_a = 0;
	a_top == 0 ? r_a : (r_a = a_top - a_ind);
	r_b = b_top - b_ind;
	if (r_b >= r_a)
		r_b = r_b - r_a;
	else
		r_b = 0;
	return (r_b);
}

int		r_b_rotation(int a_ind, int a_top, int b_ind)
{
	int	r_a;
	int	r_b;

	r_a = 0;
	r_b = -(0 - b_ind) + 1;
	a_top == -1 ? r_a : (r_a = -(0 - a_ind) + 1);
	if (r_b >= r_a)
		r_b = r_b - r_a;
	else
		r_b = 0;
	return (-(r_b));
}

int		get_b_score(t_stack *a, t_stack *b, int a_ind, int b_ind)
{
	int	r_b;

	if ((a_ind > (a->top / 2) && b_ind == (b->top / 2))
			|| (a_ind == (a->top / 2) && b_ind > (b->top / 2))
			|| (a_ind > (a->top / 2) && b_ind > (b->top / 2))
			|| (a_ind == (a->top / 2) && b_ind == (b->top / 2)))
		r_b = b_rotation(a->top, a_ind, b->top, b_ind);
	if ((a_ind == (a->top / 2) && b_ind < (b->top / 2))
			|| (a_ind < (a->top / 2) && b_ind == (b->top / 2))
			|| (a_ind < (a->top / 2) && b_ind < (b->top / 2)))
		r_b = r_b_rotation(a_ind, a->top, b_ind);
	if (a_ind > (a->top / 2) && b_ind < (b->top / 2))
		r_b = r_b_rotation(a_ind, -1, b_ind);
	if (a_ind < (a->top / 2) && b_ind > (b->top / 2))
		r_b = b_rotation(0, a_ind, b->top, b_ind);
	b->score[b_ind].r_b = r_b;
	return (if_neg(r_b));
}
