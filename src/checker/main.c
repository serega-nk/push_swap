/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 21:39:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 22:53:14 by bconchit         ###   ########.fr       */
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
		app_load(&app, argv + 1, argc - 1);
		app_play(&app);
		app_free(&app);
	}
	return (EXIT_SUCCESS);
}
