/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 05:35:09 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/19 11:11:00 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_private.h"

int		ft_list_insert(t_list *self, size_t index, void *data)
{
	t_item	**addr;
	t_item	*save;

	if (self && self->length >= index)
	{
		addr = &self->head;
		while (index && index--)
			addr = &(*addr)->next;
		save = *addr;
		*addr = (t_item *)ft_xmemalloc(sizeof(t_item));
		if (self->dupf && data)
			data = (self->dupf)(data);
		(*addr)->data = data;
		(*addr)->next = save;
		self->length++;
		return (1);
	}
	return (0);
}
