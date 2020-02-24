/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:12:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/24 06:38:22 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "gnl.h"
#include "ft_printf.h"

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

// static t_list	*gnl_strsplit(char *str, char sep)
// {
// 	t_list	**alst;
// 	t_list	*res;
// 	char	*sub;

// 	alst = &res;
// 	while ((sub = gnl_next(str, sep)))
// 	{
// 		*alst = (t_list *)ft_memalloc(sizeof(t_list));
// 		(*alst)->content = sub;
// 		alst = &(*alst)->next;
// 	}
// 	return (res);
// }

int		main(void)
{
	int		fd;
	char	*line;

	ft_putendl("===");
	fd = open("1.txt", O_RDONLY);
	
	while ((line = gnl_next(line, '\n')) > 0)
	{
		ft_putstr(line);
		ft_strdel(&line);
	}

	// while ((ret = gnl_readline(fd, &line)) > 0)
	// {
	// 	ft_putstr(line);
	// 	ft_strdel(&line);
	// }
	// gnl_clean(fd);
	// close(fd);
	return (0);
}
