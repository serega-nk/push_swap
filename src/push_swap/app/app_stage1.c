/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_stage1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 10:03:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 12:21:16 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	app_stage1(t_app *self)
{
	self->count = stack_count(self->stack_a);
	if (self->count == 0)
		app_error();
	stage1_numbers(self);
	stage1_indexes(self);
	stage1_median(self);
	stage1_play(self);
	stage1_free(self);
}
