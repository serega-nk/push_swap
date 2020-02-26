/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 01:57:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 03:12:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_destroy(t_stack **aself)
{
	if (aself && *aself)
	{
		stack_clean(*aself);
		ft_memdel((void **)aself);
	}
}
