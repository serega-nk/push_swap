/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_item.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:15:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 02:22:39 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

t_item	*stack_item(t_stack *self, void *data)
{
	t_item	*item;

	item = (t_item *)ft_xmemalloc(sizeof(t_item));
	if (self->dupf)
		data = (*self->dupf)(data);
	item->data = data;
	return (item);
}
