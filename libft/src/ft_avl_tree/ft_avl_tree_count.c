/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 05:54:08 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/28 04:29:44 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_private.h"

int		ft_avl_tree_count(t_avl_tree *self)
{
	return (self ? self->count : 0);
}
