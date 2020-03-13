/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:36:04 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/13 03:22:14 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

void	play_rra(t_play *self)
{
	if (stack_count(self->stack_a) < 2)
		return ;
	stack_reverse_rotate(self->stack_a);
	play_output(self, "rra");
}
