/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:28:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/24 04:00:18 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_PRIVATE_H
# define GNL_PRIVATE_H

# include <unistd.h>
# include "libft.h"
# include "ft_xexit.h"

# define GNL_FDS 1000
# define GNL_BUF 100

typedef struct	s_gnl
{
	t_list		*save;
	int 		eof;
}				t_gnl;

t_gnl			*gnl_state(int fd);

#endif
