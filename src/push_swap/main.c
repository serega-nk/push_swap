/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:12:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/10 09:08:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_app	app;

	ft_bzero(&app, sizeof(t_app));
	ft_on_xexit(&app_free, &app);
	if (argc > 1)
	{
		app_load(&app, argv + 1, argc - 1);
		// app_stage0(&app);
		app_stage1(&app);
		app_stage2(&app);
		app_stage3(&app);
		app_free(&app);
	}
	return (EXIT_SUCCESS);
}
