/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_stage2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:28:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/07 23:31:47 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// typedef struct	s_greedy
// {
// 	int			better;
// 	int			index;
// 	int			result;
// 	int			value;
// 	int			pos_a;
// 	int			pos_b;
// 	int			len_a;
// 	int			len_b;
// 	int			rev_a;
// 	int			rev_b;
// 	int			res_1;
// 	int			res_2;
// 	int			res_3;
// 	int			res_4;
// }				t_greedy;

// void	app_greedy2(t_app *self, t_greedy *greedy)
// {
// 	ft_bzero(greedy, sizeof(t_greedy));
// 	greedy->len_a = stack_count(self->stack_a);
// 	greedy->len_b = stack_count(self->stack_b);
// 	stack_start(self->stack_b);
// 	while (stack_next(self->stack_b, greedy->value))
// 	{
// 		greedy->pos_a = stack_place(self->stack_a, greedy->value);
// 		greedy->rev_a = greedy->len_a - greedy->pos_a;
// 		greedy->rev_b = greedy->len_b - greedy->pos_b;		
// 		greedy->res_1 = ft_max(greedy->pos_a, greedy->pos_b);
// 		greedy->res_2 = ft_max(greedy->rev_a, greedy->rev_b);
// 		greedy->res_3 = greedy->pos_a + greedy->rev_b;
// 		greedy->res_4 = greedy->rev_a + greedy->pos_b;
// 		greedy->result = ft_min(
// 			ft_min(greedy->res_1, greedy->res_2),
// 			ft_min(greedy->res_3, greedy->res_4)
// 		);
// 		if (greedy->pos_b == 0 || greedy->better < greedy->result)
// 		{
// 			greedy->better = greedy->result;
// 			greedy->index = greedy->pos_b;
// 		}
// 		if (greedy->result == 0)
// 			return ;

// 		// ft_printf("val = %2d, A pos = %2d, rev = %3d B pos = %2d, rev = %3d", greedy->value, greedy->pos_a, greedy->rev_a, greedy->pos_b, greedy->rev_b);
// 		// ft_printf(", res_1 = %2d, res_2 = %2d, res_3 = %2d, res_4 %2d", greedy->res_1, greedy->res_2, greedy->res_3, greedy->res_4);
// 		// ft_printf(", result = %d", greedy->result);

// // 		int step;
// // 		step = ft_max(pos_a, pos_b);
// // 		ft_printf(", a1 = %2d", step);
// // 		step = ft_max(count_a - pos_a, count_b - pos_b);
// // 		ft_printf(", a2 = %2d", step);
// // 		step = pos_a + count_b - pos_b;
// // 		ft_printf(", a3 = %2d", step);
// // 		step = count_a - pos_a + pos_b;
// // 		ft_printf(", a4 = %2d", step);

//  		//ft_printf("\n");
// 		greedy->pos_b++;
// 	}
// }


static void		greedy_calc(t_app *self, t_greedy *save, t_greedy *temp)
{
	ft_bzero((void *)save, sizeof(t_greedy));
	ft_bzero((void *)temp, sizeof(t_greedy));
	temp->len_a = stack_count(self->stack_a);
	temp->len_b = stack_count(self->stack_b);
	stack_start(self->stack_b);
	while (stack_next(self->stack_b, &temp->value))
	{
		temp->pos_a = stack_place(self->stack_a, temp->value);
		temp->rev_a = temp->len_a - temp->pos_a;
		temp->rev_b = temp->len_b - temp->pos_b;		
		temp->res_1 = ft_max(temp->pos_a, temp->pos_b);
		temp->res_2 = ft_max(temp->rev_a, temp->rev_b);
		temp->res_3 = temp->pos_a + temp->rev_b;
		temp->res_4 = temp->rev_a + temp->pos_b;
		temp->result = ft_min(
			ft_min(temp->res_1, temp->res_2),
			ft_min(temp->res_3, temp->res_4));
		if (temp->pos_b == 0 || save->result > temp->result)
			ft_memcpy((void *)save, (void *)&temp, sizeof(t_greedy));
		if (temp->result == 0)
			return ;
		temp->pos_b++;
	}
}

static void		greedy_exec(t_app *self, t_greedy *save)
{
	while (save->pos_a > 0 && save->pos_b > 0 && save->pos_a-- && save->pos_b--)
		play_rr(self->play);
	while (save->rev_a > 0 && save->rev_b > 0 && save->rev_a-- && save->rev_b--)
		play_rrr(self->play);
	while (save->pos_a > 0 && save->pos_a--)
		play_ra(self->play);
	while (save->pos_b > 0 && save->pos_b--)
		play_rb(self->play);
	while (save->rev_a > 0 && save->rev_a--)
		play_rra(self->play);
	while (save->rev_b > 0 && save->rev_b--)
		play_rrb(self->play);
	play_sa(self->play);
}

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

	t_greedy	greedy;
	app_greedy(self, &greedy);
	
//	ft_printf("val = %2d, A pos = %2d, rev = %3d B pos = %2d, rev = %3d", greedy.value, greedy->pos_a, greedy->rev_a, greedy->pos_b, greedy->rev_b);
// 		// ft_printf(", res_1 = %2d, res_2 = %2d, res_3 = %2d, res_4 %2d", greedy->res_1, greedy->res_2, greedy->res_3, greedy->res_4);
	ft_printf("value = %d, result = %d\n", greedy.value, greedy.result);
	

	// t_greedy	greedy;
	// int			value;

	// ft_bzero(&greedy, sizeof(t_greedy));
	// greedy.count_a = stack_count(self->stack_a);
	// greedy.count_b = stack_count(self->stack_b);
	
	// stack_start(self->stack_b);
	// while (stack_next(self->stack_b, &value))
	// {
	// 	greedy.index_a = stack_place(self->stack_a, value);
		
	// 	ft_printf("val = %2d, A pos = %2d, rev = %3d B pos = %2d, rev = %3d", value, greedy.index_a, greedy.index_a - greedy.count_a, greedy.index_b, greedy.index_b - greedy.count_b);

	// 	int step;
	// 	step = ft_max(pos_a, pos_b);
	// 	ft_printf(", a1 = %2d", step);
	// 	step = ft_max(count_a - pos_a, count_b - pos_b);
	// 	ft_printf(", a2 = %2d", step);
	// 	step = pos_a + count_b - pos_b;
	// 	ft_printf(", a3 = %2d", step);
	// 	step = count_a - pos_a + pos_b;
	// 	ft_printf(", a4 = %2d", step);

	// 	ft_printf("\n");
	// 	greedy.index_b++;
	// }
	// if (self)
	// {
	// 	ft_putendl("stage2");
	// }
}
