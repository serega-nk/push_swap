/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 07:11:52 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 07:13:12 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

void	play_destroy(t_play **aself)
{
	if (aself && *aself)
	{
		stack_destroy(&(*aself)->stack_b);
		stack_destroy(&(*aself)->stack_a);
		ft_memdel((void **)aself);
	}
}
