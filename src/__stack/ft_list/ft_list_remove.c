/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 07:05:59 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/19 11:07:04 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_private.h"

int		ft_list_remove(t_list *self, size_t index)
{
	t_item	**addr;
	t_item	*save;

	if (self && self->length > index)
	{
		addr = &self->head;
		while (index && index--)
			addr = &(*addr)->next;
		if (self->delf && (*addr)->data)
			(*self->delf)(&(*addr)->data);
		save = (*addr)->next;
		ft_memdel((void **)addr);
		*addr = save;
		self->length--;
		return (1);
	}
	return (0);
}
