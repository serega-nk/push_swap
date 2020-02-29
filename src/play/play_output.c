/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 11:31:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 11:36:25 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

void	play_output(t_play *self, char *cmd)
{
	if (self->outputf)
		(*self->outputf)(self->outputa, cmd);
}
