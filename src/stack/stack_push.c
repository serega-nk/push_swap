/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:20:34 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 05:08:46 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_push(t_stack *self, t_stack_item *item)
{
	if (item)
	{
		if (self->root)
		{
			item->prev = self->root->prev;
			item->next = self->root;
			item->prev->next = item;
			item->next->prev = item;
		}
		else
		{
			item->prev = item;
			item->next = item;
		}
		self->root = item;
		self->count++;
	}
}
