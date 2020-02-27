/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:07:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/27 03:19:02 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	app_load(t_app *self, char *arr[], int count)
{
	if (!stack_load(self->stack_a, arr, count))
		app_error();
}
