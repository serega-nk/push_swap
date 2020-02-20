/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 01:01:23 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/19 04:36:57 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_private.h"

void	ft_list_destroy(t_list **aself)
{
	if (aself && *aself)
	{
		ft_list_clear(*aself);
		ft_memdel((void **)aself);
	}
}
