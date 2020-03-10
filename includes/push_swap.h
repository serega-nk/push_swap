/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:05:48 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/10 07:30:20 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "stack.h"
# include "play.h"

typedef struct	s_greedy
{
	int			result;
	int			value;
	int			pos_a;
	int			pos_b;
	int			len_a;
	int			len_b;
	int			rev_a;
	int			rev_b;
	int			res_1;
	int			res_2;
	int			res_3;
	int			res_4;
}				t_greedy;

typedef struct	s_app
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_play		*play;
	int			count;
	int			*numbers;
	int			*indexes;
	int			median;
	int			count_median;
}				t_app;

void			app_error(void);
void			app_free(t_app *self);
void			app_load(t_app *self, char *arr[], int count);
void			app_output(t_app *self, char *cmd);
void			app_stage1(t_app *self);
void			app_stage2(t_app *self);
void			app_stage3(t_app *self);

#endif
