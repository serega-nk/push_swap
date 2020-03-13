/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_rrb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:36:12 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/13 03:22:22 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

void	play_rrb(t_play *self)
{
	if (stack_count(self->stack_b) < 2)
		return ;
	stack_reverse_rotate(self->stack_b);
	play_output(self, "rrb");
}
