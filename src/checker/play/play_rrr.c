/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:36:17 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/22 06:36:24 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	play_rrr(t_app *self)
{
	stack_reverse_rotate(self->stack_a);
	stack_reverse_rotate(self->stack_b);
}
