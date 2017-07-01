/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:08:42 by lkomarov          #+#    #+#             */
/*   Updated: 2016/12/08 12:19:25 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		hate_norm_again(char *line, t_stack *a, t_stack *b)
{
	if (ft_strequ("pa", line))
		push_a(a, b);
	else if (ft_strequ("pb", line))
		push_b(a, b);
	else if (ft_strequ("ra", line))
		rotate_stack(a);
	else if (ft_strequ("rra", line))
		rrotate_stack(a);
	else if (ft_strequ("rb", line))
		rotate_stack(b);
	else if (ft_strequ("rrb", line))
		rrotate_stack(b);
	else if (ft_strequ("rr", line))
		double_rotate_swp(a, b, 0);
	else if (ft_strequ("rrr", line))
		double_rotate_swp(a, b, 1);
	else if (ft_strequ("sa", line))
		swap_stack(a);
	else if (ft_strequ("sb", line))
		swap_stack(b);
	else if (ft_strequ("ss", line))
		double_rotate_swp(a, b, 2);
	else
		free_all(a, b, 1);
	free(line);
}

void		ft_get_command(t_stack *a, t_stack *b, int pr)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) != 0)
	{
		hate_norm_again(line, a, b);
		if (pr == 2)
		{
			print_stack(a);
			print_stack(b);
		}
	}
}

void		checker(t_stack *a, int l, int pr)
{
	t_stack	*b;

	b = newstack(l);
	ft_get_command(a, b, pr);
	if (b->top != -1)
	{
		ft_putstr("KO\n");
		free_all(a, b, 0);
		exit(1);
	}
	if (check_if_sorted(a) == 0)
		ft_putstr("OK\n");
	else
	{
		ft_putstr("KO\n");
		free_stack(a);
	}
	free_stack(b);
}

int			main(int argc, char **argv)
{
	t_stack *a;
	int		pr;

	ft_strequ("-v", argv[1]) ? pr = 2 :
		(pr = 1);
	if (argc > pr)
	{
		a = newstack(argc - pr);
		while (argc > pr)
		{
			if (error(argv[argc - 1], 1))
			{
				free_stack(a);
				return (1);
			}
			stack_push(a, ft_atoi(argv[argc - 1]));
			argc--;
		}
		if (find_duplicates(a, 1))
			return (1);
		checker(a, a->top, pr);
	}
	else
		return (0);
}
