/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:00:51 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 12:57:55 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	app_free(t_app *self)
{
	play_destroy(&self->play);
	stack_destroy(&self->stack_b);
	stack_destroy(&self->stack_a);
}
