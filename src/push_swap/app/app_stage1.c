/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_stage1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 10:03:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/10 09:46:24 by bconchit         ###   ########.fr       */
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
	self->count_sequence = sequence;
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
		if (self->indexes[index] == 0)
			array[self->count_median++] = self->numbers[index];
		index++;
	}
	ft_quicksort(array, self->count_median);
	self->median = array[self->count_median / 2];
	ft_memdel((void **)&array);
}

static void		stage1_min_max(t_app *self)
{
	int		min_index;
	int		max_index;
	int		index;

	if (self->count >= 2)
	{
		
		min_index = 0;
		max_index = 0;
		index = 1;
		while (index < self->count)
		{
			if (self->numbers[index] < self->numbers[min_index])
				min_index = index;
			if (self->numbers[index] > self->numbers[max_index])
				max_index = index;
			index++;
		}
		ft_bzero(self->indexes, sizeof(int) * self->count);
		self->indexes[min_index] = 1;
		self->indexes[max_index] = 1;
		self->count_sequence = 2;
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
	ft_printf_fd(2, "count_seq = %d\n", self->count_sequence);
	if (self->count_sequence < 2)
		stage1_min_max(self);
	ft_printf_fd(2, "count_seq = %d\n", self->count_sequence);
	stage1_median(self);
	stage1_play(self);
	ft_memdel((void **)&self->indexes);
	ft_memdel((void **)&self->numbers);
}
