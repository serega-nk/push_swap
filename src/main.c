/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:12:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/25 07:30:58 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "gnl.h"
#include "ft_xexit.h"
#include "ft_printf.h"

int		main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (gnl_readline(fd, &line) > 0)
		{
			ft_putstr(line);
			ft_strdel(&line);
		}
		gnl_clean(fd);
		close(fd);
	}
	return (0);
}
