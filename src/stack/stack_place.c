/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:36:22 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/01 20:34:05 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	direction(t_stack_item *left, t_stack_item *rigth, int value)
{
	if (left != rigth)
	{
		if (left->value <= rigth->value)
		{
			if (left->value > value)
				return (-1);
			if (value > rigth->value)
				return (1);
		}
		else
		{
			if (value > rigth->value && value < left->value)
				return (1);
		}
	}
	return (0);
}

int			stack_place(t_stack *self, int value)
{
	t_stack_item	*walk;
	int				index;
	int				direct;

	index = 0;
	if ((walk = self->root))
	{
		while ((direct = direction(walk->prev, walk, value)))
		{
			if (direct == 1)
				walk = walk->next;
			else
				walk = walk->prev;
			index += direct;
		}
	}
	return (index);
}
