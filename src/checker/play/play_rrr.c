/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 09:22:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/21 01:57:32 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	play_rrr(t_play *self)
{
	stack_reverse_rotate(self->stack_a);
	stack_reverse_rotate(self->stack_b);
}
