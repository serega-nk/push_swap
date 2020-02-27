/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 01:03:05 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 01:04:59 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

void	stack_start(t_stack *self)
{
	self->next = self->root;
}