/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:33:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/24 01:21:17 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_private.h"

static void		delf(void *content, size_t content_size)
{
	if (content_size)
		content_size = 0;
	free(content);
}

void			gnl_clean(int fd)
{
	t_gnl	*self;

	if ((self = gnl_state(fd)))
	{
		ft_lstdel(&self->save, &delf);
		ft_bzero(self, sizeof(t_gnl));
	}
}
