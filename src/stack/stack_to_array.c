/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 06:49:28 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 23:03:55 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_to_array(t_stack *self, int *array, int count)
{
	t_stack_item	*walk;
	int				index;

	if ((walk = self->root))
	{
		index = 0;
		while (index < count)
		{
			array[index] = walk->value;
			if ((walk = walk->next) == self->root)
				break ;
			index++;
		}
	}
}
