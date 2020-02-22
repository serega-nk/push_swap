/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:16:03 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/22 19:49:29 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	exec(t_app *self, const char *cmd, const char *find, void (*f)())
{
	if (ft_strcmp(cmd, find) == 0)
	{
		(*f)(self);
		return (1);
	}
	return (0);
}

static int	play(t_app *self, const char *cmd)
{
	return (self && (
		exec(self, cmd, "sa\n", &play_sa) ||
		exec(self, cmd, "sb\n", &play_sb) ||
		exec(self, cmd, "ss\n", &play_ss) ||
		exec(self, cmd, "pa\n", &play_pa) ||
		exec(self, cmd, "pb\n", &play_pb) ||
		exec(self, cmd, "ra\n", &play_ra) ||
		exec(self, cmd, "rb\n", &play_rb) ||
		exec(self, cmd, "rr\n", &play_rr) ||
		exec(self, cmd, "rra\n", &play_rra) ||
		exec(self, cmd, "rrb\n", &play_rrb) ||
		exec(self, cmd, "rrr\n", &play_rrr)));
}

int			app_play(t_app *self)
{
	char	*line;
	int		ret;

	while ((ret = gnl_readline(line)) > 0)
	{
		ret = play(self, line);
		ft_strdel(&line);
		if (ret == 0)
			return (0);
	}
	if (ret == -1)
		return (0);
	return (1);
}
