/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:34:25 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 11:38:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	play_pa(t_app *self)
{
	stack_push(self->stack_a, stack_pop(self->stack_b));
}
