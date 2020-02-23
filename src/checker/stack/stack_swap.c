/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:17:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 06:26:36 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stack_swap(t_stack *self)
{
	t_item	*a;
	t_item	*b;

	if (self->root)
	{
		a = self->root;
		b = self->root->next;
		b->prev = a->prev;
		b->next = a;
		a->prev = b;
		a->next = b->next;
		self->root = b;
	}
}
