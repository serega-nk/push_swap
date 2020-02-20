/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 05:58:45 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/21 14:25:47 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_private.h"

t_avl_node		*ft_avl_tree_node(t_avl_tree *self, void *data)
{
	t_avl_node	*node;

	node = (t_avl_node *)ft_xmemalloc(sizeof(t_avl_node));
	if (self->dupf)
		data = (*self->dupf)(data);
	node->data = ft_xcheck(data);
	self->balance = 1;
	self->count++;
	return (node);
}
