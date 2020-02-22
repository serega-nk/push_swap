/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 01:51:43 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/22 06:31:38 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack		*stack_create(void)
{
	t_stack		*self;

	self = (t_stack *)ft_xmemalloc(sizeof(t_stack));
	return (self);
}
