/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:07:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 13:08:47 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "gnl.h"
# include "stack.h"
# include "play.h"

typedef struct	s_app
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_play		*play;
}				t_app;

void			app_error(void);
void			app_free(t_app *self);
void			app_load(t_app *self, char *arr[], int count);
void			app_play(t_app *self);

#endif
