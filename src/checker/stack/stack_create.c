/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:04:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/21 04:35:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack		*stack_create(void)
{
	t_stack		*self;

	self = (t_stack *)ft_xmemalloc(sizeof(t_stack));
	return (self);
}
