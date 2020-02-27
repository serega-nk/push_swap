/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:34:25 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/27 07:26:12 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

void	play_pa(t_play *self)
{
	stack_push(self->stack_a, stack_pop(self->stack_b));
	play_output(self, "pa");
}
