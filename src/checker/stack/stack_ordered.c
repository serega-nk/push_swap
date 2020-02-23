/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ordered.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 04:15:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 14:00:14 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		stack_ordered(t_stack *self)
{
	t_item	*walk;

	walk = self->root;
	while (walk && walk->next && walk->next != self->root)
	{
		if (walk->value > walk->next->value)
			return (0);
		walk = walk->next;
	}
	return (1);
}
