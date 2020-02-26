/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 04:53:52 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 06:04:43 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_next(t_stack *self, int *avalue)
{
	if (self->next)
	{
		*avalue = self->next->value;
		if ((self->next = self->next->next) == self->root)
			self->next = NULL;
		return (1);
	}
	return (0);
}
