/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:35:30 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/22 06:35:32 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	play_ra(t_app *self)
{
	stack_rotate(self->stack_a);
}
