/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_unique.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 11:32:45 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 03:12:41 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_unique(t_stack *self, int value)
{
	t_stack_item	*walk;

	walk = self->root;
	while (walk)
	{
		if (walk->value == value)
			return (0);
		walk = walk->next;
		if (walk == self->root)
			break ;
	}
	return (1);
}
