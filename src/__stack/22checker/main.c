/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 22:50:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/21 21:29:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char *argv[])
{
	t_app	*app;
	t_play	*play;

	if (argc > 1)
	{
		play = play_create();
		play_load(play, argc, argv);
		

		// app = app_create();
		// app_run(app, argc, argv);
		


		// if (play_load(play, argc, argv) == 0)
		// {
		// 	ft_putendl_fd("Error", 2);
		// 	play_destroy(&play);
		// 	return (EXIT_FAILURE);
		// }
		// if (play(play))
		// 	ft_putendl("OK");
		// else
		// 	ft_putendl("KO");
		// play_destroy(&play);
		// if (app_load(&app, argc, argv) == 0)

		// {
		// 	ft_putendl_fd("Error", 2);
		// 	app_free(&app);
		// 	return (EXIT_FAILURE);
		// }
		// if (app_play(&app))
		// 	ft_putendl("OK");
		// else
		// 	ft_putendl("KO");
		// app_free(&app);
		ft_on_xexit(&app_free, &app);
		app_load(&app, argc, argv);
		app_play(&app);
		ft_xexit(EXIT_SUCCESS);
		// if (app_load(&app, argc, argv))
		// {
		// 	if (app_play(&app))
		// 		ft_putendl("OK");
		// 	else
		// 		ft_putendl("KO");
		// 	ft_xexit(EXIT_SUCCESS);
		// }
		// else
		// {
		// 	ft_putendl_fd("Error", 2);
		// 	ft_xexit(EXIT_FAILURE);
		// }
	}
	return (EXIT_SUCCESS);
}
