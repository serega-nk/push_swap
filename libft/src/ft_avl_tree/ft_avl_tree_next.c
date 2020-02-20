/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:53:28 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/27 18:59:14 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_private.h"

static inline int	stack_push(t_avl_tree *self, t_avl_node *walk)
{
	if (self->stack_level == FT_AVL_TREE_STACK_SIZE)
		return (0);
	self->stack[self->stack_level++] = walk;
	return (1);
}

static inline void	*walk_left(t_avl_tree *self, t_avl_node *walk)
{
	if (walk)
	{
		while (walk->left)
		{
			if (!stack_push(self, walk))
				return (NULL);
			walk = walk->left;
		}
		self->last = walk;
		return (self->last->data);
	}
	return (NULL);
}

static inline void	*walk_right(t_avl_tree *self)
{
	if (!stack_push(self, self->last))
		return (NULL);
	return (walk_left(self, self->last->right));
}

static inline void	*walk_stack(t_avl_tree *self)
{
	t_avl_node	*prev;
	t_avl_node	*walk;

	prev = self->last;
	while (self->stack_level > 0)
	{
		walk = self->stack[--self->stack_level];
		if (walk->left == prev)
		{
			self->last = walk;
			return (self->last->data);
		}
		prev = walk;
	}
	return (NULL);
}

void				*ft_avl_tree_next(t_avl_tree *self)
{
	if (self && self->root)
	{
		if (!self->last)
			return (walk_left(self, self->root));
		else if (self->last->right)
			return (walk_right(self));
		else
			return (walk_stack(self));
	}
	return (NULL);
}
