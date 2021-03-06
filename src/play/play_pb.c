/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:35:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/27 07:26:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

void	play_pb(t_play *self)
{
	stack_push(self->stack_b, stack_pop(self->stack_a));
	play_output(self, "pb");
}
