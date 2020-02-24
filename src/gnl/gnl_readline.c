/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:21:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/24 06:34:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_private.h"

static char		*gnl_next(char *str, char ch)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		if (*ptr++ == ch)
			break ;		
	}
	if (ptr > str)
		return (ft_strsub(str, 0, (size_t)(ptr - str)));
	return (NULL);
}

static t_list	*gnl_strsplit(char *str, char sep)
{
	t_list	**alst;
	t_list	*res;
	char	*sub;

	alst = &res;
	while ((sub = gnl_next(str, sep)))
	{
		*alst = (t_list *)ft_memalloc(sizeof(t_list));
		(*alst)->content = sub;
		alst = &(*alst)->next;
	}
	return (res);
}

static t_list	*gnl_strsplit(char const *str, char sep)
{
	t_list		*begin;
	t_list		**alst;
	char const	*ptr;

	alst = &begin;
	while ((ptr = ft_strchr(str, sep)) || 1)
	{
		*alst = ft_lstnew(str, (ptr ? (size_t)(ptr - str) : ft_strlen(str)) + 1);
		if (!(*alst) || !(*alst)->content || !(*alst)->content_size)
		{
			alst = &begin;
			while ((begin = *alst))
			{
				alst = &(*alst)->next;
				ft_memdel((void **)&begin->content);
				ft_memdel((void **)&begin);
			}
			return (NULL);
		}
		((char *)(*alst)->content)[(*alst)->content_size - 1] = '\0';
		if (((ptr && (str = ptr + 1)) || 1) && !ptr)
			break ;
		alst = &(*alst)->next;
	}
	return (begin);
}

static int		gnl_pop(t_gnl *self, char **aline)
{
	t_list	*save;

	if (self->save && (self->save->next || self->eof))
	{
		save = self->save;
		self->save = self->save->next;
		*aline = save->content;
		free(save);
		return (1);
	}
	return (0);
}

static void		gnl_push(t_gnl *self, char *buf, int ret)
{
	t_list	*save;
	char	*temp;

	buf[ret] = '\0';
	if ((save = gnl_strsplit(buf, '\n')))
	{
		temp = ft_strjoin(self->save->content, save->content);
		ft_memdel(&self->save->content);
		ft_memdel(&save->content);
		self->save->content = temp;
		self->save->next = save->next;
		free(save);
	}
}

int				gnl_readline(int fd, char **aline)
{
	t_gnl		*self;
	ssize_t		ret;
	char		buf[GNL_BUF];

	if (!(self = gnl_state(fd)) || read(fd, NULL, 0) < 0)
		return (-1);
	while (!(ret = gnl_pop(self, aline)))
	{
		if (self->eof)
			return (0);
		ret = read(fd, buf, GNL_BUF);
		if (ret == 0)
			self->eof = 1;
		else if (ret > 0)
			gnl_push(self, buf, ret);
		else
			return (-1);
	}
	return (1);
}
