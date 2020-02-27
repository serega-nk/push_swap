/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:12:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/27 03:19:46 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(void)
{
	// t_play	*play;

	// play = play_create();
	
	// play_destroy(&play);

	// stack = stack_create();
	
	// stack_append(stack, 1);
	// stack_append(stack, 3);
	// stack_append(stack, 4);
	// stack_append(stack, 7);
	// stack_append(stack, 8);

	// stack_rotate(stack);
	
	// int		value;

	// stack_start(stack);
	// while (stack_next(stack, &value))
	// {
	// 	ft_printf("%d\n", value);
	// }
	
	// ft_printf("%d\n", stack_get(stack, 1));

	// ft_printf("count = %d\n", stack_count(stack));

	// stack_destroy(&stack);
	
	return (0);
}


// #include <unistd.h>
// //#include "libft.h"

// void	ft_putchar_fd(int fd, char c)
// {
// 	write(fd, "||", 2);
// 	write(fd, &c, 1);
// 	write(fd, "==", 2);
// }

// void	ft_putstr_fd(char *str, int fd);

// int		main(void)
// {
// 	ft_putchar_fd(1, '0');
// 	ft_putstr_fd("123", 1);
// }

// #include <stdlib.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include "libft.h"
// #include "gnl.h"
// #include "ft_xexit.h"
// #include "ft_printf.h"

// int		main(int argc, char *argv[])
// {
// 	int		fd;
// 	char	*line;

// 	if (argc == 2)
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		while (gnl_readline(fd, &line) > 0)
// 		{
// 			ft_putstr(line);
// 			ft_strdel(&line);
// 		}
// 		gnl_clean(fd);
// 		close(fd);
// 	}
// 	return (0);
// }
