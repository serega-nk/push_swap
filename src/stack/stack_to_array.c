/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 06:49:28 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/28 06:49:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_to_array(t_stack *self, int *array, int count)
{
	int		index;

	index = 0;
	stack_start(self);
	while (index < count && stack_next(self, &array[index]))
		index++;
}
