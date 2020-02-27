/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 07:23:24 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/27 07:26:43 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

void	play_output(t_play *self, char *cmd)
{
	if (self->output)
		ft_putendl(cmd);
}
