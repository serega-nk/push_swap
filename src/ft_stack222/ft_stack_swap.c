/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:55:14 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/19 13:20:49 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int		ft_stack_swap(t_stack *self)
{
	t_item	*item_a;
	t_item	*item_b;

	if (self && self->root)
	{
		item_a = self->root;
		item_b = self->root->next;
		ft_swap(&item_a->value, &item_b->value);
		return (1);
	}
	return (0);
}
