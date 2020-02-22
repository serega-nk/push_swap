/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:33:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/21 01:47:52 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	play_destroy(t_play **aself)
{
	if (aself && *aself)
	{
		stack_destroy(&(*aself)->stack_a);
		stack_destroy(&(*aself)->stack_b);
		ft_memdel((void **)aself);
	}
}
