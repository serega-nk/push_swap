/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:12:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/27 07:39:37 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"



void	test2(int *numbers, int *indexes, int count)
{
	int		index;
	int		back;

	index = 1;
	while (index < count)
	{
		back = 0;
		while (back < index)
		{
			if (numbers[index] > numbers[back])
			{
				if (indexes[index] <= indexes[back])
					indexes[index] = indexes[back] + 1;
			}
			back++;
		}
		index++;
	}

	
}

void	test3(int *indexes, int count)
{
	int		value;
	int		index;	

	value = 0;
	index = 0;	
	while (index < count)
	{
		if (indexes[index] == value)
		{
			indexes[index] = 1;
			value++;
		}
		else
			indexes[index] = 0;
		index++;
	}
}

void	play(char *cmd)
{
	ft_putendl(cmd);
}

void	test(t_stack *stack_a, t_stack *stack_b)
{
	int		index;
	int		count;
	int		count2;
	int		*numbers;
	int		*sorted;
	int		*indexes;

	count = stack_count(stack_a);
	numbers = (int *)ft_xmemalloc(sizeof(int) * count);
	indexes = (int *)ft_xmemalloc(sizeof(int) * count);
	sorted = (int *)ft_xmemalloc(sizeof(int) * count);
	

	index = 0;
	stack_start(stack_a);
	while (stack_next(stack_a, &numbers[index]))
		index++;
	test2(numbers, indexes, count);
	test3(indexes, count);
	index = 0;
	count2  = 0;
	while (index < count)
	{
		if (!indexes[index])
			sorted[count2++] = numbers[index];
		index++;
	}
	ft_quicksort(sorted, count2);
	

	// index = 0;
	// while (index < count2)
	// {
	// 	ft_printf("= %d\n", sorted[index]);
	// 	index++;
	// }
	int		median;
	
	median = sorted[count2 / 2];	
	ft_memdel((void **)&sorted);
	// ft_printf("count2 = %d\n", count2);
	// ft_printf("count2 / 2 = %d\n", count2 / 2);
	// ft_printf("median = %d\n", );
	
	index = 0;
	while (index < count)
	{
		// ft_printf("= %d\n", numbers[index]);
		if (indexes[index])
		{
			stack_rotate(stack_a);
			play("ra");			
		}
		else
		{
			stack_push(stack_b, stack_pop(stack_a));
			play("pb");
			if (numbers[index] >= median)
			{
				stack_rotate(stack_b);
				play("rb");
			}
		}		
		index++;
	}

	int		value;
	
	ft_printf("A count = %d\n", stack_count(stack_a));
	stack_start(stack_a);
	while (stack_next(stack_a, &value))
		ft_printf(" %d\n", value);

	ft_printf("B count = %d\n", stack_count(stack_b));
	stack_start(stack_b);
	while (stack_next(stack_b, &value))
		ft_printf(" %d\n", value);		
		
	// length = len(nums)
	// if length == 1:
	// 	return 1
	// seq = [0] * length
	// for j in range(1, length):
	// 	for k in range(0, j):
	// 		if (nums[j] > nums[k]):
	// 			if seq[j] <= seq[k]:
	// 				seq[j] = seq[k] + 1
	// print(seq)
	// n = 0
	// for i, c in enumerate(seq):
	// 	if n == c:
	// 		print(nums[i])
	// 		n += 1
	


	ft_memdel((void **)&indexes);
	ft_memdel((void **)&numbers);
}

int		main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	
	stack_a = stack_create();
	stack_b = stack_create();
	stack_load(stack_a, argv + 1, argc - 1);
	ft_printf("count = %d\n", stack_count(stack_a));
	test(stack_a, stack_b);
	stack_destroy(&stack_b);
	stack_destroy(&stack_a);

	
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
