/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 09:33:14 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/20 09:49:08 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		stack_reverse_rotate(t_stack *self)
{
	if (self && self->head && self->tail && self->tail->prev)
	{
		self->head->prev = self->tail;
		self->tail = self->tail->prev;
		self->head = self->head->prev;
		self->head->prev = NULL;
		self->tail->next = NULL;
	}
}
