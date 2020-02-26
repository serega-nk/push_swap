/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:05:48 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 06:06:14 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

typedef struct	s_app
{
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_app;

void			app_init(t_app *self);
void			app_load(t_app *self, char *arr[], int count);
void			app_play(t_app *self);
void			app_free(t_app *self);
void			app_error(void);

void			play_sa(t_app *self);
void			play_sb(t_app *self);
void			play_ss(t_app *self);
void			play_pa(t_app *self);
void			play_pb(t_app *self);
void			play_ra(t_app *self);
void			play_rb(t_app *self);
void			play_rr(t_app *self);
void			play_rra(t_app *self);
void			play_rrb(t_app *self);
void			play_rrr(t_app *self);

#endif
