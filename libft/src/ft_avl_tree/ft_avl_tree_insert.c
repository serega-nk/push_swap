/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_insert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 05:56:34 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/21 14:27:37 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_private.h"

static t_avl_node	*insert(t_avl_tree *self, t_avl_node *walk, void *data)
{
	int		res;

	if (!walk)
		return (ft_avl_tree_node(self, data));
	res = (*self->cmpf)(data, walk->data);
	if (res < 0)
	{
		walk->left = insert(self, walk->left, data);
		if (self->balance)
			walk->bfactor++;
	}
	else
	{
		walk->right = insert(self, walk->right, data);
		if (self->balance)
			walk->bfactor--;
	}
	if (self->balance)
		walk = ft_avl_tree_balance(self, walk);
	return (walk);
}

void				ft_avl_tree_insert(t_avl_tree *self, void *data)
{
	if (self && data)
		self->root = insert(self, self->root, data);
}
