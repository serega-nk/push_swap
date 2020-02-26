/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:07:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 03:04:06 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_PRIVATE_H
# define STACK_PRIVATE_H

# include "libft.h"
# include "ft_xexit.h"

typedef struct	s_item
{
	struct s_item	*prev;
	struct s_item	*next;
	void			*data;
}				t_item;

typedef struct	s_stack
{
	t_item		*root;
	int			(*cmpf)(void *, void *);
	void		*(*dupf)(void *);
	void		(*delf)(void **);
	int			count;
	t_item		*next;	
}				t_stack;

void			stack_append(t_stack *self, t_item *item);
void			stack_clean(t_stack *self);
int				stack_count(t_stack *self);
t_stack			*stack_create(int (*cmpf)(), void *(*dupf)(), void (*delf)());
void			*stack_data(t_item *item);
void			stack_destroy(t_stack **aself);
int				stack_empty(t_stack *self);
void			*stack_get(t_stack *self, int index);
void			stack_item_destroy(t_stack *self, t_item **aitem);
t_item			*stack_item(t_stack *self, void *data);
int				stack_next(t_stack *self, void **adata);
int				stack_ordered(t_stack *self);
t_item			*stack_pop(t_stack *self);
void			stack_push(t_stack *self, t_item *item);
void			stack_reverse_rotate(t_stack *self);
void			stack_rotate(t_stack *self);
void			stack_start(t_stack *self);
void			stack_swap(t_stack *self);
int				stack_unique(t_stack *self, void *data);

#endif
