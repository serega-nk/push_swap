/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 09:27:20 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/20 10:03:24 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		stack_swap(t_stack *self)
{
	t_item	*item_a;	
	t_item	*item_b;
	t_item	*item_c;
	
	if (self && self->head && self->head->next)
	{
		item_a = self->head;
		item_b = self->head->next;
		item_c = self->head->next->next;
		item_b->prev = NULL;
		item_b->next = item_a;
		item_a->prev = item_b;
		item_a->next = item_c;
		if (item_a->next)
			item_a->next->prev = item_a;
		else
			self->tail = item_a;




		self->head = self->head->next;
		save = self->head->next->next;

		self->head->prev = NULL;
		if (self->head->next->next == NULL)
			self->tail = self->head->next;
	}

self && 
	t_item	*a;
	t_item	*b;
	
	a = stack_pop(self);
	b = stack_pop(self);
	stack_push(self, a);
	stack_push(self, b);
}
