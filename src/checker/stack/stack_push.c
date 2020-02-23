/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:20:34 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 06:54:11 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_item	*s_pop(t_stack *self)
{
	t_item	*item;

	item = NULL;
	if (self->root)
	{
		if (self->root != self->root->next)
		{
		}
		else
		{
			item = self->root;
			self->root = NULL;
			item->prev = NULL;
			item->next = NULL;
		}
	}
	return (item);
}

static void		s_push(t_stack *self, t_item *item)
{
	if (item)
	{
		if (self->root)
		{

		}
		else
		{
			self->root = item;
			item->prev = item;	
			item->next = item;
		}
	}	
}


void			stack_push(t_stack *self, t_stack *dest)
{
	s_push(self, s_pop(self));

	// if (self->root)
	// {
	// 	item = self->root;
	// 	if (self->root == self->root->next)
	// 		self->root = NULL;			
	// 	else
	// 	{			
	// 		item->prev->next = item->next;
	// 		item->next->prev = item->prev;
	// 		self->root = self->root->next;
	// 	}
	// 	if (dest->root)
	// 	{
	// 		item->prev = dest->root->prev;
	// 		item->next = dest->root;
	// 		item->prev->next = item;
	// 		item->next->prev = item;
	// 	}
	// 	else
	// 	{
	// 		item->prev = item;
	// 		item->next = item;
	// 	}
	// 	dest->root = item;
	// }
}
