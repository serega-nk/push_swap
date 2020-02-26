/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:59:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 02:46:08 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

void	*stack_get(t_stack *self, int index)
{
	t_item	*walk;

	if ((walk = self->root))
	{
		while (index != 0)
		{
			if (index > 0)
			{
				walk = walk->next;
				index--;
			}
			else
			{
				walk = walk->prev;
				index++;
			}
		}
		return (walk->data);
	}
	return (NULL);
}
