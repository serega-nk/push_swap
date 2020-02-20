/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 04:48:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/19 05:59:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_private.h"

void	ft_list_append(t_list *self, void *data)
{
	ft_list_insert(self, self->length, data);
}
