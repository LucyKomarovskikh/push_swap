/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:08:42 by lkomarov          #+#    #+#             */
/*   Updated: 2016/12/08 12:19:25 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_best_score(t_stack *a, t_stack *b, int a_ind, int b_ind)
{
	return (get_a_score(a, b, a_ind, b_ind) +
			get_b_score(a, b, a_ind, b_ind) +
			get_ab_score(a, b, a_ind, b_ind));
}

int		find_best_score(t_stack *b)
{
	int	fin;
	int	i;

	i = 0;
	fin = b->score[i].result;
	while (i <= b->top)
	{
		if (fin > b->score[i].result)
			fin = b->score[i].result;
		i++;
	}
	return (find_index(b, fin, 1));
}

void	re_score(t_stack *a, t_stack *b)
{
	int	top;

	top = b->top;
	while (top >= 0)
	{
		b->score[top].result = get_best_score(a, b,
				find_index(a, find_best_value(a, b->data[top]), 0), top);
		top--;
	}
}
