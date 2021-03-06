/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:16:03 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 12:58:46 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	exec(t_app *self, const char *cmd, const char *find, void (*f)())
{
	if (ft_strcmp(cmd, find) == 0)
	{
		(*f)(self->play);
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

	while (gnl_readline(STDIN_FILENO, &cmd) > 0)
	{
		if (!play(self, cmd))
		{
			ft_strdel(&cmd);
			gnl_clean(STDIN_FILENO);
			app_error();
		}
		ft_strdel(&cmd);
	}
	gnl_clean(STDIN_FILENO);
	if (stack_empty(self->stack_b) && stack_ordered(self->stack_a))
		ft_putendl("OK");
	else
		ft_putendl("KO");
}
