/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_stage2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:28:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 13:29:17 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	app_stage2(t_app *self)
{
	int 	index;
	
	self->numbers = ft_xmemalloc(sizeof(int) * self->count);
	self->indexes = ft_xmemalloc(sizeof(int) * self->count);

	self->count = stack_count(self->stack_a);
	stack_to_array(self->stack_a, self->numbers, self->count);

	ft_printf("STACK A\n");
	index = 0;
	while (index < self->count)
	{
		ft_printf(" = %d\n", self->numbers[index]);
		index++;	
	}
	
	self->count = stack_count(self->stack_b);
	stack_to_array(self->stack_b, self->numbers, self->count);

	ft_printf("STACK B\n");
	index = 0;
	while (index < self->count)
	{
		ft_printf(" = %d\n", self->numbers[index]);
		index++;	
	}
	
	ft_printf("count A = %d\n", stack_count(self->stack_a));
	ft_printf("count B = %d\n", stack_count(self->stack_b));

	// if (self)
	// {
	// 	ft_putendl("stage2");
	// }
}
