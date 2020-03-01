/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_stage2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:28:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/01 21:43:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	app_stage2(t_app *self)
{
	int 	index;

	// stack_rotate(self->stack_a);
	// stack_rotate(self->stack_a);
	// stack_rotate(self->stack_a);


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

	int		value;
	int 	count_a = stack_count(self->stack_a);
	int 	count_b = stack_count(self->stack_b);

	int		pos_a;
	int		pos_b;

	pos_b = 0;
	stack_start(self->stack_b);	
	while (stack_next(self->stack_b, &value))
	{
		pos_a = stack_place(self->stack_a, value);
		ft_printf("val = %2d, A pos = %2d, rev = %3d B pos = %2d, rev = %3d", value, pos_a, pos_a - count_a, pos_b, pos_b - count_b);
		
		int step;
		
		step = ft_max(pos_a, pos_b);
		ft_printf(", a1 = %2d", step);
		step = ft_max(count_a - pos_a, count_b - pos_b);
		ft_printf(", a2 = %2d", step);
		step = pos_a + count_b - pos_b;
		ft_printf(", a3 = %2d", step);
		step = count_a - pos_a + pos_b;
		ft_printf(", a4 = %2d", step);

		ft_printf("\n");
		pos_b++;
	}
	// if (self)
	// {
	// 	ft_putendl("stage2");
	// }
}
