/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 01:51:43 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 02:45:42 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

t_stack		*stack_create(int (*cmpf)(), void *(*dupf)(), void (*delf)())
{
	t_stack		*self;

	self = (t_stack *)ft_xmemalloc(sizeof(t_stack));
	self->cmpf = cmpf;
	self->dupf = dupf;
	self->delf = delf;
	return (self);
}
