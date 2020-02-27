/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:07:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/27 21:50:33 by bconchit         ###   ########.fr       */
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

static int	load(t_stack *self, char *str)
{
	int		count;
	int		value;

	count = 0;
	while (parse_number(&str, &value))
	{
		if (!stack_unique(self, value))
			return (0);
		stack_append(self, value);
		count++;
	}
	if (*str || count == 0)
		return (0);
	return (1);
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
