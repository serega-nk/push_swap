/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:07:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 03:04:17 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

void	stack_append(void *self, void *item);
void	stack_clean(void *self);
int		stack_count(void *self);
void	*stack_create(int (*cmpf)(), void *(*dupf)(), void (*delf)());
void	*stack_data(void *item);
void	stack_destroy(void **aself);
int		stack_empty(void *self);
void	*stack_get(void *self, int index);
void	stack_item_destroy(void *self, void **aitem);
void	*stack_item(void *self, void *data);
int		stack_next(void *self, void **adata);
int		stack_ordered(void *self);
void	*stack_pop(void *self);
void	stack_push(void *self, void *item);
void	stack_reverse_rotate(void *self);
void	stack_rotate(void *self);
void	stack_start(void *self);
void	stack_swap(void *self);
int		stack_unique(void *self, void *data);

void	*stack_int_create(void);
int		stack_int_get(void *self, int index);
void	*stack_int_item(void *self, int value);
int		stack_int_next(void *self);
int		stack_int_unique(void *self, int value);

#endif
