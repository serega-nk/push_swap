/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 05:56:34 by bconchit          #+#    #+#             */
/*   Updated: 2019/12/01 19:45:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_private.h"

static t_avl_node	*replacement(t_avl_tree *self, t_avl_node *walk, void *data)
{
	self->balance = 0;
	if (self->delf)
		(*self->delf)(&walk->data);
	if (self->dupf)
		data = (*self->dupf)(data);
	walk->data = ft_xcheck(data);
	return (walk);
}

static t_avl_node	*replace(t_avl_tree *self, t_avl_node *walk, void *data)
{
	int		res;

	if (!walk)
		return (ft_avl_tree_node(self, data));
	res = (*self->cmpf)(data, walk->data);
	if (res == 0)
		return (replacement(self, walk, data));
	if (res < 0)
	{
		walk->left = replace(self, walk->left, data);
		if (self->balance)
			walk->bfactor++;
	}
	else
	{
		walk->right = replace(self, walk->right, data);
		if (self->balance)
			walk->bfactor--;
	}
	if (self->balance)
		walk = ft_avl_tree_balance(self, walk);
	return (walk);
}

int					ft_avl_tree_replace(t_avl_tree *self, void *data)
{
	int		save;

	if (self && data)
	{
		save = self->count;
		self->root = replace(self, self->root, data);
		return (self->count - save);
	}
	return (-1);
}
