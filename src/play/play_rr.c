/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:35:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/27 07:25:53 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

void	play_rr(t_play *self)
{
	stack_rotate(self->stack_a);
	stack_rotate(self->stack_b);
	play_output(self, "rr");
}
