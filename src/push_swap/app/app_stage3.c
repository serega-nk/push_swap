/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_stage3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 05:22:14 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/11 11:03:58 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	start_index(t_stack *self)
{
	int		count;
	int		index;
	int		value;
	int		prev;

	stack_start(self);
	index = 0;
	if (stack_next(self, &prev))
		index = 1;
	while (stack_next(self, &value))
	{
		if (prev > value)
			break ;
		index++;
	}
	count = stack_count(self);
	index = index % count;
	if (index > count - index)
		index = index - count;
	return (index);
}

void		app_stage3(t_app *self)
{
	int		index;

	index = start_index(self->stack_a);
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
