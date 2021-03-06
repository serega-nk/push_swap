/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:36:53 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/27 07:25:32 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

void	play_ss(t_play *self)
{
	stack_swap(self->stack_a);
	stack_swap(self->stack_b);
	play_output(self, "ss");
}
