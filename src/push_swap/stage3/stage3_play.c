/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage3_play.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 09:48:30 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/10 09:53:49 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stage3_play(t_app *self)
{
	if (self->finally_index > 0)
	{
		while (self->finally_index-- > 0)
			play_ra(self->play);
	}
	else if (self->finally_index < 0)
	{
		while (self->finally_index++ < 0)
			play_rra(self->play);
	}
}