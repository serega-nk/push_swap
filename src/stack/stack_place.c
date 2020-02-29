/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:36:22 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 17:08:43 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_place(t_stack *self, int value)
{
	t_stack_item	*walk;
	int				index;

	index = 0;
	if ((walk = self->root))
	{
		while (walk->value < value)
		{
			index++;
			if ((walk = walk->next) == self->root)
				break ;
		}
	}
	return (index);
}
