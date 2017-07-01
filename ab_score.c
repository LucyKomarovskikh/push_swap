/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:08:42 by lkomarov          #+#    #+#             */
/*   Updated: 2016/12/08 12:19:25 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ab_rotation(int a_top, int a_ind, int b_top, int b_ind)
{
	int	r_a;
	int	r_b;
	int	r_ab;

	r_a = a_top - a_ind;
	r_b = b_top - b_ind;
	r_a >= r_b ? r_ab = r_b
		: (r_ab = r_a);
	return (r_ab);
}

int		r_ab_rotation(int a_ind, int b_ind)
{
	int	r_a;
	int	r_b;
	int r_ab;

	r_a = -(0 - a_ind) + 1;
	r_b = -(0 - b_ind) + 1;
	r_a >= r_b ? r_ab = r_b
		: (r_ab = r_a);
	return (-(r_ab));
}

int		get_ab_score(t_stack *a, t_stack *b, int a_ind, int b_ind)
{
	int	r_ab;

	r_ab = 0;
	if ((a_ind > (a->top / 2) && b_ind == (b->top / 2))
			|| (a_ind == (a->top / 2) && b_ind > (b->top / 2))
			|| (a_ind > (a->top / 2) && b_ind > (b->top / 2))
			|| (a_ind == (a->top / 2) && b_ind == (b->top / 2)))
		r_ab = ab_rotation(a->top, a_ind, b->top, b_ind);
	if ((a_ind == (a->top / 2) && b_ind < (b->top / 2))
			|| (a_ind < (a->top / 2) && b_ind == (b->top / 2))
			|| (a_ind < (a->top / 2) && b_ind < (b->top / 2)))
		r_ab = r_ab_rotation(a_ind, b_ind);
	b->score[b_ind].r_ab = r_ab;
	return (if_neg(r_ab));
}
