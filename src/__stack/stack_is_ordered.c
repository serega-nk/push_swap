/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_ordered.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 05:09:43 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/20 07:47:12 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			stack_is_ordered(t_stack *self)
{
	t_item	*walk;

	if (self->head)
	{
		walk = self->head;
		while (walk->next)
		{
			if (walk->value > walk->next->value)
				return (0);
			walk = walk->next;
		}
	}
	return (1);
}
