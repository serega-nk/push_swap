/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:35:30 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 07:01:23 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

void	play_ra(t_play *self)
{
	stack_rotate(self->stack_a);
}