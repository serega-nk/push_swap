/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 07:02:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 11:35:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAY_H
# define PLAY_H

# include "stack.h"

typedef struct	s_play
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	void		(*outputf)();
	void		*outputa;
}				t_play;

t_play			*play_create(t_stack *stack_a, t_stack *stack_b,
	void (*outputf)(), void *outputa);
void			play_destroy(t_play **aself);
void			play_output(t_play *self, char *cmd);
void			play_pa(t_play *self);
void			play_pb(t_play *self);
void			play_ra(t_play *self);
void			play_rb(t_play *self);
void			play_rr(t_play *self);
void			play_rra(t_play *self);
void			play_rrb(t_play *self);
void			play_rrr(t_play *self);
void			play_sa(t_play *self);
void			play_sb(t_play *self);
void			play_ss(t_play *self);

#endif
