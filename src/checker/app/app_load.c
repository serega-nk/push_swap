/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:07:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/23 03:22:52 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	parse_number(const char *str, int *avalue)
{
	int		negative;
	long	prev;
	long	curr;

	negative = (*str == '-') ? 1 : 0;
	if (*str == '-' || *str == '+')
		str++;
	if (ft_isdigit(*str))
	{
		curr = 0;
		while (ft_isdigit(*str))
		{
			prev = curr;
			curr = curr * 10 + (*str++ - '0');
			if ((int)(curr - negative) < (int)(prev - negative))
				return (0);
		}
		if (*str == '\0')
		{
			*avalue = (int)(curr * (negative ? -1 : 1));
			return (1);
		}
	}
	return (0);
}

void		app_load(t_app *self, char *arr[], int count)
{
	int		index;
	int		value;

	index = 0;
	while (index < count)
	{
		if (!parse_number(arr[index], &value))
			app_exit(APP_EXIT_ERROR);
		if (!stack_append(self->stack_a, value))
			app_exit(APP_EXIT_ERROR);
		index++;
	}
}
