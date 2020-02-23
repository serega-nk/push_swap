/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:58:59 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 01:03:44 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_PRIVATE_H
# define GNL_PRIVATE_H

# include <unistd.h>
# include "libft.h"
# include "ft_xexit.h"

# define GNL_FDS 1000
# define GNL_BUF 100

// typedef struct	s_gnl
// {
// 	char		*fds[GNL_FDS];
// 	char		buf[GNL_BUF];
// }				t_gnl;

typedef struct	s_gnl
{
	char		*save;
	t_list		*more;
	int 		eof;
}				t_gnl;

t_gnl			*gnl_state(int fd);

#endif
