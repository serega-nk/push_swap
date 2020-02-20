/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 09:22:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/20 13:43:03 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	play_rrr(t_app *self)
{
	stack_reverse_rotate(self->stack_a);
	stack_reverse_rotate(self->stack_b);
}
