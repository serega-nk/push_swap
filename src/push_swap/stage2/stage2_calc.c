/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage2_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 10:08:03 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/10 10:10:35 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	greedy_place(t_stack *self, int place)
{
	int		index;
	int		value;
	int		prev;

	index = 0;
	stack_start(self);
	while (stack_next(self, &value))
	{
		if (index == 0)
			prev = value;
		if (prev > value)
		{
			if (place > prev || place < value)
				return (index);
		}
		else
		{
			if (place > prev && place < value)
				return (index);
		}
		index++;
	}
	return (0);
}

void		stage2_calc(t_app *self, t_greedy *save, t_greedy *temp)
{
	ft_bzero((void *)temp, sizeof(t_greedy));
	ft_bzero((void *)save, sizeof(t_greedy));
	temp->len_a = stack_count(self->stack_a);
	temp->len_b = stack_count(self->stack_b);
	stack_start(self->stack_b);
	while (stack_next(self->stack_b, &temp->value))
	{
		temp->pos_a = greedy_place(self->stack_a, temp->value);
		temp->rev_a = temp->len_a - temp->pos_a;
		temp->rev_b = temp->len_b - temp->pos_b;
		temp->res_1 = ft_max(temp->pos_a, temp->pos_b);
		temp->res_2 = ft_max(temp->rev_a, temp->rev_b);
		temp->res_3 = temp->pos_a + temp->rev_b;
		temp->res_4 = temp->rev_a + temp->pos_b;
		temp->result = ft_min(
			ft_min(temp->res_1, temp->res_2),
			ft_min(temp->res_3, temp->res_4));
		if (temp->pos_b == 0 || save->result > temp->result)
			ft_memcpy((void *)save, (void *)temp, sizeof(t_greedy));
		if (save->result == 0)
			return ;
		temp->pos_b++;
	}
}
