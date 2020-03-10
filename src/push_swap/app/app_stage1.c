/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_stage1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 10:03:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/10 07:42:59 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		stage1_longest_increasing_subsequence(t_app *self)
{
	int		index;
	int		back;
	int		sequence;

	sequence = 0;
	index = 1;
	while (index < self->count)
	{
		back = 0;
		while (back < index)
		{
			if (self->numbers[index] > self->numbers[back])
				if (self->indexes[index] <= self->indexes[back])
					self->indexes[index] = self->indexes[back] + 1;
			back++;
		}
		if (sequence < self->indexes[index])
			sequence = self->indexes[index];
		index++;
	}
	while (--index >= 0)
		if ((self->indexes[index] = (self->indexes[index] == sequence)))
			sequence--;
}

static void		stage1_median(t_app *self)
{
	int		*array;
	int		index;

	array = (int *)ft_xmemalloc(sizeof(int) * self->count);
	index = 0;
	self->count_median = 0;
	while (index < self->count)
	{
		if (!self->indexes[index])
			array[self->count_median++] = self->numbers[index];
		index++;
	}
	ft_quicksort(array, self->count_median);
	self->median = array[self->count_median / 2];
	ft_memdel((void **)&array);
}

static void		stage1_play(t_app *self)
{
	int		index;

	index = 0;
	while (index < self->count && self->count_median > 0)
	{
		if (self->indexes[index])
			play_ra(self->play);
		else
		{
			play_pb(self->play);
			if (self->numbers[index] >= self->median)
				play_rb(self->play);
			self->count_median--;
		}
		index++;
	}
}

void			app_stage1(t_app *self)
{
	self->count = stack_count(self->stack_a);
	if (self->count == 0)
		app_error();
	self->numbers = ft_xmemalloc(sizeof(int) * self->count);
	self->indexes = ft_xmemalloc(sizeof(int) * self->count);
	stack_to_array(self->stack_a, self->numbers, self->count);
	stage1_longest_increasing_subsequence(self);
	stage1_median(self);
	stage1_play(self);
	ft_memdel((void **)&self->indexes);
	ft_memdel((void **)&self->numbers);
}
