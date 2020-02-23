/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:08:23 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 01:04:35 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_private.h"

static void		del(char *str, size_t len)
{
	len = 0;
	ft_strdel(&str);
}

int				gnl_close(int fd)
{
	t_gnl	*gnl;
	
	if ((gnl = gnl_state(fd)))
	{
		ft_strdel(&gnl->save);
		ft_lstdel(&gnl->more, &del);
		gnl->eof = 0;
	}
	return (close(fd));
}
