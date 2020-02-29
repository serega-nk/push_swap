/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage1_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:11:59 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 12:24:21 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stage1_numbers(t_app *self)
{
	self->numbers = ft_xmemalloc(sizeof(int) * self->count);
	stack_to_array(self->stack_a, self->numbers, self->count);
}