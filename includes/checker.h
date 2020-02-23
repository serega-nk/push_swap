/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:07:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 03:25:53 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
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
int				stack_append(t_stack *self, int value);
void			stack_push(t_stack *self, t_stack *dest);
void			stack_reverse_rotate(t_stack *self);
void			stack_rotate(t_stack *self);
void			stack_swap(t_stack *self);

typedef enum	e_exit
{
	APP_EXIT_OK,
	APP_EXIT_KO,
	APP_EXIT_ERROR
}				t_exit;

typedef struct	s_app
{
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_app;

void			app_init(t_app *self);
void			app_load(t_app *self, char *arr[], int count);
void			app_play(t_app *self);
void			app_free(t_app *self);
void			app_exit(t_exit exit);

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
