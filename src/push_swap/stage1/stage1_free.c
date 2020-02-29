/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage1_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:20:21 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 12:20:52 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stage1_free(t_app *self)
{
	ft_memdel((void **)&self->indexes);
	ft_memdel((void **)&self->numbers);
}
