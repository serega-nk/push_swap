/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:34:47 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/24 01:01:51 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_private.h"

t_gnl	*gnl_state(int fd)
{
	static t_gnl	save[GNL_FDS];
	static int		zero = 0;

	if (fd >= 0 && fd < GNL_FDS)
	{
		if (zero == 0)
		{
			ft_bzero(save, sizeof(t_gnl) * GNL_FDS);
			zero = 1;
		}
		return (&save[fd]);
	}
	return (NULL);
}
