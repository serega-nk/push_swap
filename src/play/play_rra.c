/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:36:04 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/27 07:25:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

void	play_rra(t_play *self)
{
	stack_reverse_rotate(self->stack_a);
	play_output(self, "rra");
}
