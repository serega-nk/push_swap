/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_item.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:15:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 12:19:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_item	*stack_item(int value)
{
	t_item	*self;

	self = (t_item *)ft_xmemalloc(sizeof(t_item));
	self->value = value;
	return (self);
}
