/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:28:03 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 03:31:05 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	app_exit(t_exit exit)
{
	if (exit == APP_EXIT_ERROR)
	{
		ft_putendl_fd("Error", 2);
		ft_xexit(EXIT_FAILURE);
	}
	else if (exit == APP_EXIT_OK)
	{
		ft_putendl("OK");
		ft_xexit(EXIT_SUCCESS);
	}
	else if (exit == APP_EXIT_KO)
	{
		ft_putendl("KO");
		ft_xexit(EXIT_SUCCESS);
	}
}
