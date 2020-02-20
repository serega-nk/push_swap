/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:21:00 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/20 07:46:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		stack_destroy(t_stack **aself)
{
	if (aself && *aself)
	{
		ft_memdel((void **)aself);
	}
}
