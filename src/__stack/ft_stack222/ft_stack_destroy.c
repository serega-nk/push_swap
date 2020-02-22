/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:26:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/20 03:53:19 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_destroy(t_stack **aself)
{
	if (aself && *aself)
	{
		ft_stack_clear(*aself);
		ft_memdel((void **)aself);
	}
}
