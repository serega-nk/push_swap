/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:33:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 06:48:34 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_private.h"

void			gnl_clean(int fd)
{
	t_gnl	*self;

	if ((self = gnl_state(fd)))
	{
		if (self->save)
		{
			while (*self->save)
			{
				ft_strdel(self->save);
				self->save++;
			}
		}
		ft_memdel((void **)&self->addr);
		ft_bzero(self, sizeof(t_gnl));
	}
}
