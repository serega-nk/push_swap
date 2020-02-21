/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:04:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/20 07:46:40 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		stack_append(t_stack *self, int value)
{
	t_item	*item;

	item = (t_item *)ft_xmemalloc(sizeof(t_item));
	item->value = value;
	if (self->head == NULL)
	{
		self->head = item;
		self->tail = item;
	}
	else
	{
		item->prev = self->tail;
		self->tail->next = item;
		self->tail = item;
	}
	self->count++;
}
