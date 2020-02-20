/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:32:45 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/21 04:16:58 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl_tree_private.h"

t_avl_tree		*ft_avl_tree(int (*cmpf)())
{
	return (ft_avl_tree_create(cmpf, NULL, NULL));
}
