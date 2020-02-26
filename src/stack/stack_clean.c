/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:38:15 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 03:12:10 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_clean(t_stack *self)
{
	t_stack_item	*item;

	while ((item = stack_pop(self)))
		stack_item_destroy(&item);
}
