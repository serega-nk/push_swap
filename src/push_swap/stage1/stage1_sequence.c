/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage1_sequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 01:30:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/11 11:02:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		stage1_sequence_0(t_app *self, int offset)
{
	int		index;
	int		back;

	ft_bzero(self->indexes, sizeof(int) * self->count);
	self->sequence = 0;
	self->offset = offset;
	self->index = 1;
	while (self->index < self->count)
	{
		index = (self->index + self->offset) % self->count;
		self->back = 0;
		while (self->back < self->index)
		{
			back = (self->back + self->offset) % self->count;
			if (self->numbers[index] > self->numbers[back])
				if (self->indexes[index] <= self->indexes[back])
					self->indexes[index] = self->indexes[back] + 1;
			self->back++;
		}
		if (self->sequence < self->indexes[index] + 1)
			self->sequence = self->indexes[index] + 1;
		self->index++;
	}
}

static void		stage1_sequence_1(t_app *self)
{
	int		index;
	int		sequence;

	sequence = self->sequence;
	self->back = self->count;
	while (self->back > 0)
	{
		self->back--;
		index = (self->back + self->offset) % self->count;
		if (self->indexes[index] == sequence - 1)
		{
			self->indexes[index] = 1;
			if (sequence == self->sequence)
				self->final = (index + 1) % self->count;
			if (sequence == 1)
				self->start = index;
			sequence--;
		}
		else
			self->indexes[index] = 0;
	}
}

static void		stage1_sequence_2(t_app *self)
{
	int		index;
	int		next;
	int		back;
	int		curr;

	next = -1;
	index = self->count;
	while (index-- > 1)
	{
		curr = (index + self->offset) % self->count;
		if (self->indexes[curr] == 1)
		{
			back = (index - 1 + self->offset) % self->count;
			if (self->indexes[back] == 0 &&
				self->numbers[back] > self->numbers[curr])
			{
				if (next == -1 || self->numbers[back] <= self->numbers[next])
					self->indexes[back] = 2;
			}
			next = curr;
		}
	}
}

void			stage1_sequence(t_app *self)
{
	int		sequence;

	stage1_sequence_0(self, 0);
	if (self->sequence == 0)
		stage1_sequence_0(self, 1);
	stage1_sequence_1(self);
	if (self->sequence != self->count)
	{
		stage1_sequence_0(self, self->start);
		if (self->sequence != self->count && self->start != self->final)
		{
			sequence = self->sequence;
			stage1_sequence_0(self, self->final);
			if (sequence > self->sequence)
				stage1_sequence_0(self, self->start);
		}
		stage1_sequence_1(self);
	}
	stage1_sequence_2(self);
}
