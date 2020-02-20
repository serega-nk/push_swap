/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_balance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:05:20 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/21 19:47:20 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_private.h"
#include "ft_printf.h"

static t_avl_node	*left_rotate(t_avl_node *node_a, t_avl_node *node_b)
{
	node_a->right = node_b->left;
	node_b->left = node_a;
	node_a->bfactor += (1 - node_b->bfactor++);
	return (node_b);
}

static t_avl_node	*big_left_rotate(
	t_avl_node *node_a, t_avl_node *node_b, t_avl_node *node_c)
{
	node_b->left = node_c->right;
	node_c->right = node_b;
	node_a->right = node_c->left;
	node_c->left = node_a;
	node_a->bfactor = (node_c->bfactor == -1) ? 1 : 0;
	node_b->bfactor = (node_c->bfactor == 1) ? -1 : 0;
	node_c->bfactor = 0;
	return (node_c);
}

static t_avl_node	*right_rotate(t_avl_node *node_a, t_avl_node *node_b)
{
	node_a->left = node_b->right;
	node_b->right = node_a;
	node_a->bfactor -= (1 + node_b->bfactor--);
	return (node_b);
}

static t_avl_node	*big_right_rotate(
	t_avl_node *node_a, t_avl_node *node_b, t_avl_node *node_c)
{
	node_b->right = node_c->left;
	node_c->left = node_b;
	node_a->left = node_c->right;
	node_c->right = node_a;
	node_a->bfactor = (node_c->bfactor == 1) ? -1 : 0;
	node_b->bfactor = (node_c->bfactor == -1) ? 1 : 0;
	node_c->bfactor = 0;
	return (node_c);
}

t_avl_node			*ft_avl_tree_balance(t_avl_tree *self, t_avl_node *walk)
{
	if (walk && walk->bfactor == -2 && walk->right)
	{
		if (walk->right->bfactor == -1 ||
			walk->right->bfactor == 0)
			walk = left_rotate(walk, walk->right);
		else if (walk->right->bfactor == 1 && walk->right->left &&
			walk->right->left->bfactor >= -1 &&
			walk->right->left->bfactor <= 1)
			walk = big_left_rotate(walk, walk->right, walk->right->left);
	}
	else if (walk && walk->bfactor == 2 && walk->left)
	{
		if (walk->left->bfactor == 1 ||
			walk->left->bfactor == 0)
			walk = right_rotate(walk, walk->left);
		else if (walk->left->bfactor == -1 && walk->left->right &&
			walk->left->right->bfactor >= -1 &&
			walk->left->right->bfactor <= 1)
			walk = big_right_rotate(walk, walk->left, walk->left->right);
	}
	if (walk && walk->bfactor == 0)
		self->balance = 0;
	return (walk);
}
