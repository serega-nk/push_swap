/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:13:19 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/24 04:34:39 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_private.h"

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

static int		gnl_pop(t_gnl *gnl, char **aline, int *alen)
{
	return (0);
}

static void		gnl_push(t_gnl *gnl, char *buf, int len)
{
	t_list	*walk;
	
	buf[len - 1] = '\n';
	gnl_strsplit(buf, '\n');
}

int				gnl_readline(int fd, char **aline)
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
