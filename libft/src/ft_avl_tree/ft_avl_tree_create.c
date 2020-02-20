/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 23:59:38 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/21 04:24:45 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_private.h"

t_avl_tree	*ft_avl_tree_create(int (*cmpf)(), void *(*dupf)(), void (*delf)())
{
	t_avl_tree	*self;

	self = (t_avl_tree *)ft_xmemalloc(sizeof(t_avl_tree));
	self->cmpf = cmpf;
	self->dupf = dupf;
	self->delf = delf;
	return (self);
}
