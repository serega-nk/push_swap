/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 08:41:25 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 10:29:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	app_free(t_app *self)
{
	ft_memdel((void **)&self->indexes);
	ft_memdel((void **)&self->numbers);
	play_destroy(&self->play);
	stack_destroy(&self->stack_b);
	stack_destroy(&self->stack_a);
}
