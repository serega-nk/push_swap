/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 07:12:01 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 11:35:21 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

t_play	*play_create(t_stack *stack_a, t_stack *stack_b,
	void (*outputf)(), void *outputa)
{
	t_play	*self;

	self = (t_play *)ft_xmemalloc(sizeof(t_play));
	self->stack_a = stack_a;
	self->stack_b = stack_b;
	self->outputf = outputf;
	self->outputa = outputa;
	return (self);
}
