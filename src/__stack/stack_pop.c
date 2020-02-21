/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:21:05 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/20 07:47:18 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_item		*stack_pop(t_stack *self)
{
	t_item	*item;

	if (self && self->head)
	{
		item = self->head;
		if ((self->head = self->head->next))
			self->head->prev = NULL;
		item->prev = NULL;
		item->next = NULL;
		if (self->tail == item)
			self->tail = NULL;
		self->count--;
		return (item);
	}
	return (NULL);
}
