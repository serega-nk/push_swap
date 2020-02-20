/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 04:29:28 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/19 04:43:57 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_private.h"

void	ft_list_clear(t_list *self)
{
	t_item	*walk;

	if (self)
	{
		while (self->head)
		{
			walk = self->head;
			self->head = walk->next;
			if (self->delf && walk->data)
				(*self->delf)(walk->data);
			ft_memdel((void **)&walk);
		}
		self->length = 0;
		self->tail = NULL;
	}
}
