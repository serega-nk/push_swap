/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 10:25:59 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/11 08:33:57 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	app_output(t_app *self, char *cmd)
{
	if (self)
		ft_putendl(cmd);
}
