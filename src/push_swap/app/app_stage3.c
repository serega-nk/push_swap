/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_stage3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 05:22:14 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/10 06:12:57 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	finally_place(t_app *self)
{
	int		index;
	int		value;
	int		prev;

	index = 0;
	stack_start(self->stack_a);
	while (stack_next(self->stack_a, &value))
	{
		if (index == 0)
			prev = value;
		if (prev > value)
			return (index);
		index++;
	}
	return (0);
}

void		app_stage3(t_app *self)
{
	int		count;
	int		index;

	index = finally_place(self);
	count = stack_count(self->stack_a);
	if (index > count - index)
		index -= count;
	if (index > 0)
	{
		while (index-- > 0)
			play_ra(self->play);
	}
	else if (index < 0)
	{
		while (index++ < 0)
			play_rra(self->play);
	}
}
