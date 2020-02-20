/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 01:01:23 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/19 04:36:02 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_private.h"

t_list	*ft_list_create(void *(*dupf)(), void (*delf)())
{
	t_list	*self;

	self = (t_list *)ft_xmemalloc(sizeof(t_list));
	self->dupf = dupf;
	self->delf = delf;
	return (self);
}
