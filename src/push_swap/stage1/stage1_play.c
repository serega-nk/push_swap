/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage1_play.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:11:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 12:24:28 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stage1_play(t_app *self)
{
	int		index;

	index = 0;
	while (index < self->count)
	{
		if (self->indexes[index])
			play_ra(self->play);
		else
		{
			play_pb(self->play);
			if (self->numbers[index] >= self->median)
				play_rb(self->play);
		}
		index++;
	}
}
