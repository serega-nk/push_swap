/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:57:04 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/22 23:26:05 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_private.h"

t_gnl	*gnl_state(int fd)
{
	static t_gnl	*fds = NULL;
	
	if (fd >= 0 && fd < GNL_FDS)
	{
		if (fds == NULL)
			fds = (t_gnl *)ft_xmemalloc(sizeof(t_gnl) * GNL_FDS);
		return (fds + fd);
	}
	return (NULL);
}
