/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:08:42 by lkomarov          #+#    #+#             */
/*   Updated: 2016/12/08 12:19:25 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(t_stack *a, int length)
{
	t_stack	*b;
	int		pos;

	b = newstack(length);
	a = s_normalize(a);
	reset_min_max(a);
	mini_sort_three(a, b);
	if (!three_sorted(a))
	{
		swap_stack(a);
		ft_putstr("sa\n");
	}
	while (b->top != -1)
	{
		re_score(a, b);
		pos = find_best_score(b);
		perform(a, b, pos);
	}
	final_rotation(a);
	free_stack(a);
	free_stack(b);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	i = argc;
	if (argc > 1)
	{
		a = newstack(argc - 1);
		while (argc > 1)
		{
			if (error(argv[argc - 1], 0))
			{
				free_stack(a);
				return (1);
			}
			stack_push(a, ft_atoi(argv[argc - 1]));
			argc--;
		}
		if (!check_if_sorted(a) || find_duplicates(a, 0))
			return (1);
		reset_min_max(a);
		push_swap(a, i);
	}
	else
		return (0);
}
