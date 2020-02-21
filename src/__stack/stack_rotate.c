/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 09:33:14 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/20 09:49:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		stack_rotate(t_stack *self)
{
	if (self && self->tail && self->head && self->head->next)
	{
		self->tail->next = self->head;
		self->head = self->head->next;
		self->tail = self->tail->next;
		self->head->prev = NULL;
		self->tail->next = NULL;
	}
}
