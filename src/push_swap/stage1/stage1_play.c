/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage1_play.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 09:45:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/11 11:14:52 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			stage1_play(t_app *self)
{
	int		index;
	int		count;

	index = 0;
	count = self->count - self->sequence;
	while (index < self->count && count > 0)
	{
		if (self->indexes[index] == 0)
		{
			play_pb(self->play);
			if (self->numbers[index] >= self->median)
				play_rb(self->play);
			count--;
		}
		else if (self->indexes[index] == 1)
			play_ra(self->play);
		else if (self->indexes[index] == 2)
		{
			self->indexes[index] = 1;
			play_sa(self->play);
			count--;
			index--;
		}
		index++;
	}
}
