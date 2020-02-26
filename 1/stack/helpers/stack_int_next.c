/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:14:47 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 03:03:16 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

int		stack_int_next(t_stack *self, int *value)
{
	int		ret;
	t_item	*item;

	if ((ret = stack_next(self, &item)))
		*value = (int)item->data;
	return (ret);
}
