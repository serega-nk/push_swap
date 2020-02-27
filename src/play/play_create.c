/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 07:12:01 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 07:15:24 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

t_play	*play_create(void)
{
	t_play	*self;

	self = (t_play *)ft_xmemalloc(sizeof(t_play));
	self->stack_a = stack_create();
	self->stack_b = stack_create();
	return (self);
}
