/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:07:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/20 09:48:36 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include "libft.h"
# include "ft_xexit.h"

typedef struct		s_item
{
	struct s_item	*prev;
	struct s_item	*next;
	int				value;
}					t_item;

typedef struct		s_stack
{
	t_item			*head;
	t_item			*tail;
	size_t			count;
}					t_stack;

t_stack				*stack_create(void);
void				stack_destroy(t_stack **aself);
size_t				stack_count(t_stack *self);
int					stack_is_empty(t_stack *self);
int					stack_is_ordered(t_stack *self);
void				stack_append(t_stack *self, int value);
t_item				*stack_pop(t_stack *self);
void				stack_push_(t_stack *self, t_item *item);

void				stack_push(t_stack *self, t_stack *dest);
void				stack_swap(t_stack *self);
void				stack_rotate(t_stack *self);
void				stack_reverse_rotate(t_stack *self);

typedef struct		s_app
{
	t_stack			*stack_a;
	t_stack			*stack_b;
}					t_app;

void				app_rra(t_app *self);
void				app_rrb(t_app *self);

#endif
