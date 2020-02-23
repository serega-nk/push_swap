/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 03:54:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 03:55:20 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	app_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_xexit(EXIT_FAILURE);
}
