/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_apply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 06:08:19 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/21 13:52:31 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_private.h"

static void		recursive(t_avl_node *walk, void (*applyf)(), void *arg)
{
	if (walk)
	{
		recursive(walk->left, applyf, arg);
		(*applyf)(arg, walk->data);
		recursive(walk->right, applyf, arg);
	}
}

void			ft_avl_tree_apply(t_avl_tree *self, void (*applyf)(), void *arg)
{
	if (self && applyf)
		recursive(self->root, applyf, arg);
}
