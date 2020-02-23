/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 22:15:03 by bconchit          #+#    #+#             */
/*   Updated: 2019/09/23 00:43:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 32

typedef struct	s_context
{
	int					fd;
	int					eof;
	char				*save;
	t_list				*more;
	struct s_context	*next;
}				t_context;

typedef struct	s_state
{
	char				*buff;
	t_context			*ctx;
	int					ret;
	char				**line;
}				t_state;

int				get_next_line(const int fd, char **line);

#endif
