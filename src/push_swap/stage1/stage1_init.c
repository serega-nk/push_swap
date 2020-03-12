/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage1_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 01:40:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/12 23:35:49 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stage1_init(t_app *self)
{
	self->numbers = ft_xmemalloc(sizeof(int) * self->count);
	self->indexes = ft_xmemalloc(sizeof(int) * self->count);
	stack_to_array(self->stack_a, self->numbers, self->count);
}
