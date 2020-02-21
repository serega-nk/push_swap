/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 04:48:23 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/21 06:38:39 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		app_load(t_app *self, int argc, char *argv[])
{
	
	return (1);
}
	

	// // If no argument is given checker stops and displays nothing.
	// if (argc > 1)
	// {
	// 	app = app_create();
	// 	if (app_load(app, argc, argv))
	// 	{

	// 	}
	// 	app_play(app);
	// 	app_destroy(app);
	// }

// • You have to write a program named checker, which will get as an argument the
// stack a formatted as a list of integers. The first argument should be at the top of
// the stack (be careful about the order). 
// • Checker will then wait and read instructions on the standard input, each instruction
// will be followed by ’\n’. Once all the instructions have been read, checker will
// execute them on the stack received as an argument.
// • If after executing those instructions, stack a is actually sorted and b is empty, then
// checker must display "OK" followed by a ’\n’ on the standard output. In every
// other case, checker must display "KO" followed by a ’\n’ on the standard output.
// • In case of error, you must display Error followed by a ’\n’ on the standard error.
// Errors include for example: some arguments are not integers, some arguments are
// bigger than an integer, there are duplicates, an instruction don’t exist and/or is
// incorrectly formatted.
// Thanks to the checker program, you will be able to check if the
// list of instructions you’ll generate with the program push_swap is
// actually sorting the stack properly.

	// t_stack		*stack_a;

	// if (argc > 1)
	// {
	// 	while (argc-- > 1)
	// 	{
	// 		ft_putendl(argv[argc]);
	// 	}
	// 	ft_putendl_fd("Error", 2);
	// 	stack_a = stack_create();
	// 	// stack_append(stack_a, 1);
	// 	// stack_append(stack_a, 4);
	// 	// stack_append(stack_a, 4);
	// 	if (stack_is_ordered(stack_a))
	// 	{
	// 		ft_putendl("Is ordered");
	// 	}
	// 	stack_destroy(&stack_a);
	// }
