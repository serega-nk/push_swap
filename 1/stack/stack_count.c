/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:59:42 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 01:00:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

int		stack_count(t_stack *self)
{
	return (self->count);
}