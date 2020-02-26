/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_unique.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 11:32:45 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 02:31:56 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

int		stack_unique(t_stack *self, void *data)
{
	t_item	*walk;

	if (self->cmpf)
	{
		walk = self->root;
		while (walk)
		{
			if ((*self->cmpf)(walk->data, data) == 0)
				return (0);
			walk = walk->next;
			if (walk == self->root)
				break ;
		}
	}
	return (1);
}
