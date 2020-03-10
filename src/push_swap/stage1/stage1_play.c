/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage1_play.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 09:45:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/10 09:46:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stage1_play(t_app *self)
{
	int		index;

	index = 0;
	while (index < self->count && self->count_median > 0)
	{
		if (self->indexes[index] == 1)
			play_ra(self->play);
		else if (self->indexes[index] == 2)
		{
			play_sa(self->play);
			play_ra(self->play);
		}
		else if (self->indexes[index] == 3)
		{
			play_rra(self->play);
			play_sa(self->play);
			play_ra(self->play);
			play_ra(self->play);
		}
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