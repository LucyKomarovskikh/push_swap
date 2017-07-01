/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:08:42 by lkomarov          #+#    #+#             */
/*   Updated: 2016/12/08 12:19:25 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct	s_score
{
	int			result;
	int			r_a;
	int			r_b;
	int			r_ab;
}				t_score;

typedef	struct	s_stack
{
	int			*data;
	int			top;
	int			min;
	int			max;
	t_score		*score;
}				t_stack;

void			stack_push(t_stack *stack, int value);
int				stack_pop(t_stack *stack);
void			push_a(t_stack *a, t_stack *b);
void			push_b(t_stack *a, t_stack *b);
void			rotate_stack(t_stack *stack);
void			rrotate_stack(t_stack *stack);
void			swap_stack(t_stack *stack);
void			double_rotate_swp(t_stack *a, t_stack *b, int fl);
void			find_min(t_stack *s);
void			find_max(t_stack *s);
void			print_stack(t_stack *stack);
int				if_neg(int i);
t_stack			*newstack(int argc);
t_stack			*s_normalize(t_stack *s);
int				find_index(t_stack *s, int n, int flag);
void			reset_min_max(t_stack *stack);
void			mini_sort_three(t_stack *a, t_stack *b);
int				three_sorted(t_stack *a);
int				a_rotation(int a_top, int a_ind, int b_top, int b_ind);
int				r_a_rotation(int a_ind, int b_top, int b_ind);
int				b_rotation(int a_top, int a_ind, int b_top, int b_ind);
int				r_b_rotation(int a_ind, int a_top, int b_ind);
int				ab_rotation(int a_top, int a_ind, int b_top, int b_ind);
int				r_ab_rotation(int a_ind, int b_ind);
void			perform_r(t_stack *s, int i, int fl);
void			perform_rab(t_stack *a, t_stack *b, int i);
void			perform(t_stack *a, t_stack *b, int pos);
void			final_rotation(t_stack *a);
int				find_best_value(t_stack *s, int i);
void			re_score(t_stack *a, t_stack *b);
int				find_best_score(t_stack *b);
int				check_if_sorted(t_stack *a);
int				error(char *arg, int fl);
int				find_duplicates(t_stack *a, int fl);
void			ft_get_command(t_stack *a, t_stack *b, int pr);
void			push_swap(t_stack *a, int length);
void			checker(t_stack *a, int l, int pr);
int				get_a_score(t_stack *a, t_stack *b, int a_ind, int b_ind);
int				get_b_score(t_stack *a, t_stack *b, int a_ind, int b_ind);
int				get_ab_score(t_stack *a, t_stack *b, int a_ind, int b_ind);
void			free_stack(t_stack *s);
void			free_all(t_stack *a, t_stack *b, int fl);
void			hate_norm_again(char *line, t_stack *a, t_stack *b);
#endif
