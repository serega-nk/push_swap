/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:21:00 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/19 13:18:49 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack		*ft_stack(void)
{
	t_stack		*self;

	self = (t_stack *)ft_xmemalloc(sizeof(t_stack));
	return (self);
}
