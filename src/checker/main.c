/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 22:50:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/20 07:34:03 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char *argv[])
{
	t_stack		*stack_a;

	if (argc > 1)
	{
		while (argc-- > 1)
		{
			ft_putendl(argv[argc]);
		}
		ft_putendl_fd("Error", 2);
		stack_a = stack_create();
		// stack_append(stack_a, 1);
		// stack_append(stack_a, 4);
		// stack_append(stack_a, 4);
		if (stack_is_ordered(stack_a))
		{
			ft_putendl("Is ordered");
		}
		stack_destroy(&stack_a);
	}
	return (0);
}
