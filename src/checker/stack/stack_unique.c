/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_unique.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 11:32:45 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 11:34:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	    stack_unique(t_stack *self, int value)
{
	t_item	*walk;

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