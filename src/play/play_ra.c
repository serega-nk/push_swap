/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:35:30 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/13 03:21:56 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

void	play_ra(t_play *self)
{
	if (stack_count(self->stack_a) < 2)
		return ;
	stack_rotate(self->stack_a);
	play_output(self, "ra");
}
