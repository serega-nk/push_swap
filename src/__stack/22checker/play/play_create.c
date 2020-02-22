/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:33:20 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/21 01:57:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_play	*play_create(void)
{
	t_play	*self;

	self = (t_play *)ft_xmemalloc(sizeof(t_play));
	self->stack_a = stack_create();
	self->stack_b = stack_create();
	return (self);
}
