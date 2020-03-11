/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_stage1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 10:03:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/11 10:58:04 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	app_stage1(t_app *self)
{
	stage1_init(self);
	stage1_sequence(self);
	stage1_median(self);
	stage1_play(self);
	stage1_free(self);
}
