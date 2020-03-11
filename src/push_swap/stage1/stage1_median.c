/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage1_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:57:08 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/11 11:00:39 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stage1_median(t_app *self)
{
	int		*array;
	int		index;

	array = (int *)ft_xmemalloc(sizeof(int) * self->count);
	index = 0;
	self->count_median = 0;
	while (index < self->count)
	{
		if (self->indexes[index] == 0)
			array[self->count_median++] = self->numbers[index];
		index++;
	}
	ft_quicksort(array, self->count_median);
	self->median = array[self->count_median / 2];
	ft_memdel((void **)&array);
}
