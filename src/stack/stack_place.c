/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:36:22 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 21:13:28 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_place(t_stack *self, int value)
{
	t_stack_item	*walk;
	int				index;

	index = 0;
	if ((walk = self->root) && walk != walk->next)
	{
		while (index < self->count)
		{
			if (walk->prev->value > walk->value)
			
			if (walk->prev->value <= walk->value)
				if (walk->prev->value <= value && walk->value >= value)
					break ;
			walk = walk->next;
			index++;
		}
	}
	return (index);
}
