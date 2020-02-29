/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 10:03:02 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 11:49:34 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	app_load(t_app *self, char *arr[], int count)
{
	self->stack_a = stack_create();
	self->stack_b = stack_create();
	if (!stack_load(self->stack_a, arr, count))
		app_error();
	self->play = play_create(self->stack_a, self->stack_b, &app_output, self);
}
