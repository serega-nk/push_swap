/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:04:23 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 02:07:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

static int	cmpf(int a, int b)
{
	return (a - b);
}

t_stack		*stack_int_create(void)
{
	return (stack_create(&cmpf, NULL, NULL));
}
