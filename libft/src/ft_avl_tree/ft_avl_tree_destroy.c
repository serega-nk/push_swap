/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 23:41:24 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/19 18:03:42 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_private.h"

static void		recursive(t_avl_tree *self, t_avl_node **addr)
{
	if (*addr)
	{
		recursive(self, &(*addr)->left);
		recursive(self, &(*addr)->right);
		if (self->delf && (*addr)->data)
			(*self->delf)(&(*addr)->data);
		ft_memdel((void **)addr);
	}
}

void			ft_avl_tree_destroy(t_avl_tree **addr)
{
	if (addr && *addr)
	{
		recursive(*addr, &(*addr)->root);
		ft_memdel((void **)addr);
	}
}
