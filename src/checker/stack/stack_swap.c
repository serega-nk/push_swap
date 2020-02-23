/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:17:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 11:53:37 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stack_swap(t_stack *self)
{
	t_item	*save;

	save = stack_pop(self);
	stack_rotate(self);
	stack_push(self, save);
	stack_reverse_rotate(self);
}
