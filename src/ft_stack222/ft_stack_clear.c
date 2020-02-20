/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:27:42 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/20 03:53:21 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

static void		destroy(t_item *walk)
{
	t_item	*save;

	walk->prev->next = NULL;
	while (walk)
	{
		save = walk->next;
		ft_memdel((void **)&walk);
		walk = save;
	}
}

void			ft_stack_clear(t_stack *self)
{
	if (self && self->root)
	{
		destroy(self->root);
		self->root = NULL;
		self->length = 0;
	}
}
