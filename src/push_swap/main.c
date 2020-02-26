/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:12:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 06:50:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "stack.h"

int		main(void)
{
	t_stack		*stack;

	stack = stack_create();
	
	stack_append(stack, 1);
	stack_append(stack, 3);
	stack_append(stack, 4);
	stack_append(stack, 7);
	stack_append(stack, 8);

	stack_rotate(stack);
	
	int		value;

	stack_start(stack);
	while (stack_next(stack, &value))
	{
		ft_printf("%d\n", value);
	}
	
	ft_printf("%d\n", stack_get(stack, 1));

	ft_printf("count = %d\n", stack_count(stack));

	stack_destroy(&stack);
	
	return (0);
}
