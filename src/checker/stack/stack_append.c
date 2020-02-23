/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 03:38:48 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 04:21:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_unique(t_stack *self, int value)
{
	t_item	*walk;

	walk = self->root;
	while (walk)
	{
		if (walk->value == value)
			return (0);
		walk = walk->next;
		if (walk == self->root)
			break ;
	}
	return (1);
}

int			stack_append(t_stack *self, int value)
{
	t_item	*item;

	if (check_unique(self, value))
	{
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
		return (1);
	}
	return (0);
}
