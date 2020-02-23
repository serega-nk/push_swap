/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:46:24 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 13:07:05 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

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

static int		gnl_init(t_state **asta, int fd, char **line)
{
	t_context	**actx;
	t_context	*ctx;

	if (!*asta && !(*asta = (t_state *)ft_memalloc(sizeof(t_state))))
		return (0);
	if (!(*asta)->buff && !((*asta)->buff = (char *)malloc(BUFF_SIZE + 1)))
		return (0);
	actx = &(*asta)->ctx;
	while (*actx && (*actx)->fd != fd)
		actx = &(*actx)->next;
	if ((ctx = *actx))
		*actx = (*actx)->next;
	if (!ctx && !(ctx = (t_context *)ft_memalloc(sizeof(t_context))))
		return (0);
	ctx->fd = fd;
	if (ctx != (*asta)->ctx)
		ctx->next = (*asta)->ctx;
	(*asta)->ctx = ctx;
	(*asta)->ret = 0;
	(*asta)->line = line;
	return (1);
}

static int		gnl_pop(t_state *sta)
{
	t_context	*tmp;
	t_list		*lst;

	if (sta->ctx->eof == 0 && (!sta->ctx->save || !sta->ctx->more))
		return (0);
	if (sta->ctx->eof == 1 && sta->ctx->save && !*sta->ctx->save)
		ft_strdel(&sta->ctx->save);
	if (sta->ctx->eof == 1 && !sta->ctx->save)
	{
		tmp = sta->ctx;
		sta->ctx = sta->ctx->next;
		free(tmp);
		sta->ret = 0;
		return (1);
	}
	(*sta->line) = sta->ctx->save;
	sta->ctx->save = NULL;
	if (sta->ctx->more)
	{
		lst = sta->ctx->more;
		sta->ctx->more = lst->next;
		sta->ctx->save = (char *)lst->content;
		free(lst);
	}
	return ((sta->ret = 1));
}

static int		gnl_push(t_state *sta)
{
	char	*ptr;
	char	*tmp;

	sta->ret = -1;
	if ((ptr = ft_strchr(sta->buff, '\n')))
		*ptr++ = '\0';
	if (sta->ctx->save)
	{
		tmp = ft_strjoin(sta->ctx->save, sta->buff);
		ft_strdel(&sta->ctx->save);
		sta->ctx->save = tmp;
	}
	else
		sta->ctx->save = ft_strdup(sta->buff);
	if (!sta->ctx->save)
		return (1);
	if (ptr && !*ptr)
	{
		(*sta->line) = sta->ctx->save;
		sta->ctx->save = NULL;
		return ((sta->ret = 1));
	}
	if (ptr && *ptr && !(sta->ctx->more = gnl_strsplit(ptr, '\n')))
		return (1);
	return ((sta->ret = 0));
}

int				get_next_line(const int fd, char **line)
{
	static t_state	*sta = NULL;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (gnl_init(&sta, fd, line))
	{
		while (sta->ret >= 0)
		{
			if (gnl_pop(sta))
				return (sta->ret);
			sta->ret = read(fd, sta->buff, BUFF_SIZE);
			if (sta->ret > 0)
			{
				sta->buff[sta->ret] = '\0';
				if (gnl_push(sta))
					return (sta->ret);
			}
			else if (sta->ret == 0)
				sta->ctx->eof = 1;
		}
	}
	return (-1);
}
