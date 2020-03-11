/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_stage2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:47:19 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/11 11:01:32 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		greedy_place(t_app *self, int place)
{
	int		index;
	int		value;
	int		prev;

	index = 0;
	stack_start(self->stack_a);
	while (stack_next(self->stack_a, &value))
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

static void		greedy_calc(t_app *self, t_greedy *save, t_greedy *temp)
{
	ft_bzero((void *)temp, sizeof(t_greedy));
	ft_bzero((void *)save, sizeof(t_greedy));
	temp->len_a = stack_count(self->stack_a);
	temp->len_b = stack_count(self->stack_b);
	stack_start(self->stack_b);
	while (stack_next(self->stack_b, &temp->value))
	{
		temp->pos_a = greedy_place(self, temp->value);
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

static void		greedy_fixx(t_app *self, t_greedy *save)
{
	if (self)
	{
		if (save->result == save->res_1)
		{
			save->rev_a = 0;
			save->rev_b = 0;
		}
		else if (save->result == save->res_2)
		{
			save->pos_a = 0;
			save->pos_b = 0;
		}
		else if (save->result == save->res_3)
		{
			save->pos_b = 0;
			save->rev_a = 0;
		}
		else if (save->result == save->res_4)
		{
			save->pos_a = 0;
			save->rev_b = 0;
		}
	}
}

static void		greedy_play(t_app *self, t_greedy *save)
{
	while (save->pos_a > 0 && save->pos_b > 0 && save->pos_a-- && save->pos_b--)
		play_rr(self->play);
	while (save->rev_a > 0 && save->rev_b > 0 && save->rev_a-- && save->rev_b--)
		play_rrr(self->play);
	while (save->pos_a > 0 && save->pos_a--)
		play_ra(self->play);
	while (save->pos_b > 0 && save->pos_b--)
		play_rb(self->play);
	while (save->rev_a > 0 && save->rev_a--)
		play_rra(self->play);
	while (save->rev_b > 0 && save->rev_b--)
		play_rrb(self->play);
	play_pa(self->play);
}

void			app_stage2(t_app *self)
{
	t_greedy	save;
	t_greedy	temp;

	while (!stack_empty(self->stack_b))
	{
		greedy_calc(self, &save, &temp);
		greedy_fixx(self, &save);
		greedy_play(self, &save);
	}
}
