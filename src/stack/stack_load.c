/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:07:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/03/14 17:29:42 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	parse_number(char **addr, int *avalue)
{
	int		negative;
	long	prev;
	long	curr;

	while (**addr == ' ')
		(*addr)++;
	negative = (**addr == '-') ? 1 : 0;
	if ((**addr == '-' || **addr == '+') && *(*addr + 1))
		(*addr)++;
	if (ft_isdigit(**addr))
	{
		curr = 0;
		while (ft_isdigit(**addr))
		{
			prev = curr;
			curr = curr * 10 + (*(*addr)++ - '0');
			if ((int)(curr - negative) < (int)(prev - negative))
				return (-1);
		}
		if (**addr == '\0' || **addr == ' ')
			return ((*avalue = (int)(curr * (negative ? -1 : 1))) || 1);
	}
	return (0);
}

static int	load(t_stack *self, char *str)
{
	int		value;
	int		ret;

	while ((ret = parse_number(&str, &value)) > 0)
	{
		if (!stack_unique(self, value))
			return (0);
		stack_append(self, value);
	}
	if (ret == -1)
		return (0);
	return (!*str);
}

int			stack_load(t_stack *self, char *arr[], int count)
{
	int		index;

	index = 0;
	while (index < count)
	{
		if (!load(self, arr[index]))
			return (0);
		index++;
	}
	return (1);
}
