/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:14:47 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 02:25:53 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

int		stack_int_get(t_stack *self, int index)
{
	return ((int)stack_get(self, index));
}
