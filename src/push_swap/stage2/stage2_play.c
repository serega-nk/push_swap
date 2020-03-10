/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage2_play.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 09:45:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/10 10:07:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stage2_play(t_app *self, t_greedy *save)
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
