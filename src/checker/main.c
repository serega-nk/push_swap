/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 21:39:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/22 06:27:41 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char *argv[])
{
	t_app	app;

	ft_on_xexit(&app_free, &app);
	if (argc > 1)
	{
		app_init(&app);
		if (app_load(&app, argv + 1, argc - 1))
		{
			if (app_play(&app))
				ft_putendl("OK");
			else
				ft_putendl("KO");
			ft_xexit(EXIT_SUCCESS);
		}
		else
		{
			ft_putendl_fd("Error", 2);
			ft_xexit(EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
