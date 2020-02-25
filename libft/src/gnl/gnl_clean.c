/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:33:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/25 05:50:31 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_private.h"

void			gnl_clean(int fd)
{
	t_gnl	*self;

	if ((self = gnl_state(fd)))
	{
		while (*self->save)
		{
			ft_strdel(self->save);
			self->save++;
		}
		ft_memdel((void **)&self->addr);
		ft_bzero(self, sizeof(t_gnl));
	}
}
