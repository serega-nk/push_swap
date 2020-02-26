/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:07:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 05:08:05 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"
# include "ft_xexit.h"

typedef struct	s_stack_item
{
	struct s_stack_item	*prev;
	struct s_stack_item	*next;
	int					value;
}				t_stack_item;

typedef struct	s_stack
{
	t_stack_item		*root;
	t_stack_item		*next;
	int					count;
}				t_stack;

void			stack_append(t_stack *self, int value);
void			stack_clean(t_stack *self);
int				stack_count(t_stack *self);
t_stack			*stack_create(void);
void			stack_destroy(t_stack **aself);
int				stack_empty(t_stack *self);
int				stack_get(t_stack *self, int index);
void			stack_item_destroy(t_stack_item **aself);
t_stack_item	*stack_item(int value);
int				stack_next(t_stack *self, int *avalue);
int				stack_ordered(t_stack *self);
t_stack_item	*stack_pop(t_stack *self);
void			stack_push(t_stack *self, t_stack_item *item);
void			stack_reverse_rotate(t_stack *self);
void			stack_rotate(t_stack *self);
void			stack_start(t_stack *self);
void			stack_swap(t_stack *self);
int				stack_unique(t_stack *self, int value);

#endif
