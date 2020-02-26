/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:14:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 05:08:53 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack_item	*stack_pop(t_stack *self)
{
	t_stack_item	*item;

	if ((item = self->root))
	{
		if (item == item->next)
		{
			self->root = NULL;
		}
		else
		{
			self->root = item->next;
			item->next->prev = item->prev;
			item->prev->next = item->next;
		}
		item->prev = NULL;
		item->next = NULL;
		self->count--;
	}
	return (item);
}
