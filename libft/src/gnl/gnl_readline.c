/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:21:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/25 16:17:19 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_private.h"

static int		gnl_pop(t_gnl *self, char **aline)
{
	if (self->save)
	{
		if (self->save[0] && (self->save[1] || self->eof))
		{
			*aline = self->save[0];
			self->save[0] = NULL;
			self->save++;
			return (1);
		}
	}
	return (0);
}

static void		gnl_push(t_gnl *self, char *str)
{
	char	*part;
	char	*temp;

	part = NULL;
	if (self->save)
		part = *self->save;
	ft_memdel((void **)&self->addr);
	self->addr = gnl_split(str, '\n');
	self->save = self->addr;
	if (part)
	{
		temp = *self->save;
		*self->save = ft_strjoin(part, temp);
		ft_strdel(&part);
		ft_strdel(&temp);
	}
}

int				gnl_readline(int fd, char **aline)
{
	t_gnl		*self;
	ssize_t		ret;
	char		buf[GNL_BUF + 1];

	if (!(self = gnl_state(fd)) || read(fd, NULL, 0) < 0)
		return (-1);
	while (!gnl_pop(self, aline))
	{
		if (self->eof)
			return (0);
		if ((ret = read(fd, buf, GNL_BUF)) == -1)
			return (-1);
		buf[ret] = '\0';
		if (ret == 0)
			self->eof = 1;
		else
			gnl_push(self, buf);
	}
	return (1);
}
