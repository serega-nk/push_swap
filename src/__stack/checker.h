/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:07:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/22 06:20:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "libft.h"
# include "ft_xexit.h"

typedef struct	s_item
{
	struct s_item	*prev;
	struct s_item	*next;
	int				value;
}				t_item;

typedef struct	s_stack
{
	t_item		*head;
	t_item		*tail;
	size_t		count;
}				t_stack;

t_stack			*stack_create(void);
void			stack_destroy(t_stack **aself);
void			stack_append(t_stack *self, int value);

typedef struct	s_app
{
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_app;

void			app_init(t_app *self);
int				app_load(t_app *self, char *arr[], int count);
int				app_play(t_app *self);
void			app_free(t_app *self);

// # include "ft_xexit.h"

// t_stack			*stack_create(void);
// void			stack_destroy(t_stack **aself);

// typedef struct	s_play
// {
// 	t_stack		*stack_a;
// 	t_stack		*stack_b;
// }				t_play;

// t_play			*play_create(void);
// void			play_destroy(t_play **aself);
// int				play_execute(t_play *self, const char *cmd);
// void			play_sa(t_play *self);
// void			play_sb(t_play *self);
// void			play_ss(t_play *self);
// void			play_pa(t_play *self);
// void			play_pb(t_play *self);
// void			play_ra(t_play *self);
// void			play_rb(t_play *self);
// void			play_rr(t_play *self);
// void			play_rra(t_play *self);
// void			play_rrb(t_play *self);
// void			play_rrr(t_play *self);



// int				app_play(t_app *self);
// void			app_free(t_app *self);

#endif
