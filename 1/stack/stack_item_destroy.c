/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_item_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:44:45 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 02:29:17 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

void	stack_item_destroy(t_stack *self, t_item **aitem)
{
	if (self->delf)
		(*self->delf)(&(*aitem)->data);
	ft_memdel((void **)aitem);
}
