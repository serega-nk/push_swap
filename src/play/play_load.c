/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:07:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 07:30:32 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"

static int	parse_number(char **addr, int *avalue)
{
	int		negative;
	long	prev;
	long	curr;

	while (**addr == ' ')
		(*addr)++;
	negative = (**addr == '-') ? 1 : 0;
	if (**addr == '-' || **addr == '+')
		(*addr)++;
	if (ft_isdigit(**addr))
	{
		curr = 0;
		while (ft_isdigit(**addr))
		{
			prev = curr;
			curr = curr * 10 + (*(*addr)++ - '0');
			if ((int)(curr - negative) < (int)(prev - negative))
				return (0);
		}
		if (**addr == '\0' || **addr == ' ')
			return ((*avalue = (int)(curr * (negative ? -1 : 1))) || 1);
	}
	return (0);
}

int			play_load(t_play *self, char *arr[], int count)
{
	int		index;
	int		value;
	char	*ptr;
	int		ret;

	index = 0;
	while (index < count)
	{
		ptr = arr[index];
		ret = 0;
		while (parse_number(&ptr, &value))
		{
			if (!stack_unique(self->stack_a, value))
				return (0);
			stack_append(self->stack_a, value);
			ret++;
		}
		if (*ptr || ret == 0)
			return (0);
		index++;
	}
	return (1);
}
