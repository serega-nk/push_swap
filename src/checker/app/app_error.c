/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 05:10:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/21 05:12:37 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	app_error(void)
{
	ft_putendl_fd("Error", 2);
	ft_xexit(EXIT_FAILURE);
}
