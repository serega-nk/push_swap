/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:05:48 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 12:20:59 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "stack.h"
# include "play.h"

typedef struct	s_app
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_play		*play;
	int			count;
	int			*numbers;
	int			*indexes;
	int			median;
}				t_app;

void			app_error(void);
void			app_free(t_app *self);
void			app_load(t_app *self, char *arr[], int count);
void			app_output(t_app *self, char *cmd);
void			app_stage1(t_app *self);
void			app_stage2(t_app *self);

void			stage1_free(t_app *self);
void			stage1_indexes(t_app *self);
void			stage1_median(t_app *self);
void			stage1_numbers(t_app *self);
void			stage1_play(t_app *self);

#endif
