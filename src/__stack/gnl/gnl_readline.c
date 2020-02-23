/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:13:19 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 01:02:36 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_private.h"

static int	gnl_pop(t_gnl *gnl, char **aline, int *alen)
{
	return (0);
}

static void	gnl_push(t_gnl *gnl, char *buf, int len)
{
	
}

int			gnl_readline(int fd, char **aline)
{
	t_gnl	*gnl;
	int		len;
	char	buf[GNL_BUF];

	if (!(gnl = gnl_state(fd)) || read(fd, NULL, 0) == -1)
		return (-1);
	while (gnl_pop(gnl, aline, &len) == 0)
	{
		len = read(fd, buf, GNL_BUF);
		if (len < 0)
			return (-1);
		else if (len == 0)
			gnl->eof = 1;
		else
			gnl_push(gnl, buf, len);
	}
	return (len);
}
