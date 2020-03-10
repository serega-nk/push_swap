/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage3_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 09:58:48 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/10 10:10:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	finally_place(t_stack *self)
{
	int		index;
	int		value;
	int		prev;

	index = 0;
	stack_start(self);
	while (stack_next(self, &value))
	{
		if (index == 0)
			prev = value;
		if (prev > value)
			return (index);
		index++;
	}
	return (0);
}

void		stage3_calc(t_app *self)
{
	int		pos;
    int		rev;

	pos = finally_place(self->stack_a);
	rev = stack_count(self->stack_a) - pos;
    if (pos < rev)
        self->finally_index = pos;
    else
        self->finally_index = -rev;
}