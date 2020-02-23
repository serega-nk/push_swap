/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:16:03 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 03:29:39 by bconchit         ###   ########.fr       */
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
	return (
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
		exec(self, cmd, "rrr\n", &play_rrr));
}

void		app_play(t_app *self)
{
	char	*cmd;
	int		ret;

	while ((ret = get_next_line(STDIN_FILENO, &cmd)) > 0)
	{
		ft_putendl(cmd);
		ret = play(self, cmd);
		ft_strdel(&cmd);
		if (!ret)
			app_exit(APP_EXIT_ERROR);
	}
	if (ret < 0)
		app_exit(APP_EXIT_ERROR);
	app_exit(APP_EXIT_OK);
	app_exit(APP_EXIT_KO);
}
