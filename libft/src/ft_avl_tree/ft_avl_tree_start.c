/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:52:35 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/27 18:53:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_private.h"

void	ft_avl_tree_start(t_avl_tree *self)
{
	if (self)
	{
		self->stack_level = 0;
		self->last = NULL;
	}
}
