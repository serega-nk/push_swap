/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 01:42:05 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/25 02:52:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_private.h"

static char		**recursive(char *str, char sep, int index)
{
	char	**res;
	int		len;

	if (!*str)
		return (char **)ft_xmemalloc((index + 1) * sizeof(char *));
	len = 0;
	while (str[len])
	{
		if (str[len++] == sep)
			break ;
	}
	res = recursive(str + len, sep, index + 1);
	res[index] = ft_strsub(str, 0, len);
	if (!res[index])
	{
		index++;
		while (res[index])
			ft_strdel(&res[index++]);
		ft_memdel((void **)&res);
		ft_xexit(EXIT_FAILURE);
	}
	return (res);
}

char			**gnl_split(char *str, char sep)
{
	return (recursive(str, sep, 0));
}
