/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:55:14 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/20 03:56:38 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_push(t_stack *self, int value)
{
	t_item	*item;

	item = (t_item *)ft_xmemalloc(sizeof(t_item));
	item->value = value;
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
}
