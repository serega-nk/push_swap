/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_item.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:15:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 03:12:22 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack_item	*stack_item(int value)
{
	t_stack_item	*self;

	self = (t_stack_item *)ft_xmemalloc(sizeof(t_stack_item));
	self->value = value;
	return (self);
}
