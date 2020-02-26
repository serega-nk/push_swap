/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:07:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/26 07:16:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "gnl.h"
# include "play.h"

typedef struct	s_app
{
	t_play		*play;
}				t_app;

void			app_init(t_app *self);
void			app_load(t_app *self, char *arr[], int count);
void			app_play(t_app *self);
void			app_free(t_app *self);
void			app_error(void);

#endif
