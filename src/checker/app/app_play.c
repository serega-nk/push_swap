/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:16:03 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 14:09:00 by bconchit         ###   ########.fr       */
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
		exec(self, cmd, "sa", &play_sa) ||
		exec(self, cmd, "sb", &play_sb) ||
		exec(self, cmd, "ss", &play_ss) ||
		exec(self, cmd, "pa", &play_pa) ||
		exec(self, cmd, "pb", &play_pb) ||
		exec(self, cmd, "ra", &play_ra) ||
		exec(self, cmd, "rb", &play_rb) ||
		exec(self, cmd, "rr", &play_rr) ||
		exec(self, cmd, "rra", &play_rra) ||
		exec(self, cmd, "rrb", &play_rrb) ||
		exec(self, cmd, "rrr", &play_rrr));
}

void		app_play(t_app *self)
{
	char	*cmd;
	int		ret;

	while ((ret = get_next_line(STDIN_FILENO, &cmd)) > 0)
	{
		ret = play(self, cmd);
		ft_strdel(&cmd);
		if (!ret)
			app_error();
	}
	if (ret < 0)
		app_error();
	if (stack_empty(self->stack_b) && stack_ordered(self->stack_a))
		ft_putendl("OK");
	else
		ft_putendl("KO");
}
