/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:08:42 by lkomarov          #+#    #+#             */
/*   Updated: 2016/12/08 12:19:25 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_duplicates(t_stack *a, int fl)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i <= a->top)
	{
		while (j <= a->top)
		{
			if (a->data[i] == a->data[j])
			{
				fl == 1 ? ft_putstr("Error\n") : fl;
				free_stack(a);
				exit(1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int		check_if_sorted(t_stack *a)
{
	int	i;

	i = a->top;
	while (i >= 1)
	{
		if ((a->data[i] > a->data[i - 1]))
			return (1);
		i--;
	}
	free_stack(a);
	return (0);
}

int		error(char *arg, int fl)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (!isdigit(arg[i]))
		{
			fl == 1 ? ft_putstr("Error\n") : fl;
			return (1);
		}
		i++;
	}
	if ((ft_atoi(arg) < -2147483648) || (ft_atoi(arg) > 2147483647))
	{
		fl == 1 ? ft_putstr("Error\n") : fl;
		return (1);
	}
	return (0);
}
