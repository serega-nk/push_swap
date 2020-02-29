/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage1_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:17:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 12:17:53 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stage1_median(t_app *self)
{
	int		*array;
	int		index;
	int		count;

	array = (int *)ft_xmemalloc(sizeof(int) * self->count);
	index = 0;
	count = 0;
	while (index < self->count)
	{
		if (!self->indexes[index])
			array[count++] = self->numbers[index];
		index++;
	}
	ft_quicksort(array, count);
	self->median = array[count / 2];
	ft_memdel((void **)&array);
}
