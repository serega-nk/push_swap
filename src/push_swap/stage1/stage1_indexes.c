/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage1_indexes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:13:30 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 13:42:11 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		longest_increasing_subsequence(t_app *self)
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

void			stage1_indexes(t_app *self)
{
	self->indexes = ft_xmemalloc(sizeof(int) * self->count);
	longest_increasing_subsequence(self);
}
