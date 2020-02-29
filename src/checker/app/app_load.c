/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:07:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 12:58:14 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	app_load(t_app *self, char *arr[], int count)
{
	self->stack_a = stack_create();
	self->stack_b = stack_create();
	if (!stack_load(self->stack_a, arr, count))
		app_error();
	self->play = play_create(self->stack_a, self->stack_b, NULL, NULL);
}
