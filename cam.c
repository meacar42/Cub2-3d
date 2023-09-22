/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:03:40 by beyildir          #+#    #+#             */
/*   Updated: 2023/08/08 10:24:03 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cam_right(t_data *bm)
{
	bm->game.old = bm->game.dirx;
	bm->game.dirx = bm->game.dirx * cos(bm->game.rotate_speed) - \
	bm->game.diry * sin(bm->game.rotate_speed);
	bm->game.diry = bm->game.old * sin(bm->game.rotate_speed) + \
	bm->game.diry * cos(bm->game.rotate_speed);
	bm->game.old2 = bm->game.planex;
	bm->game.planex = bm->game.planex * cos(bm->game.rotate_speed) - \
	bm->game.planey * sin(bm->game.rotate_speed);
	bm->game.planey = bm->game.old2 * sin(bm->game.rotate_speed) + \
	bm->game.planey * cos(bm->game.rotate_speed);
}

void	cam_left(t_data *bm)
{
	bm->game.old = bm->game.dirx;
	bm->game.dirx = bm->game.dirx * cos(-bm->game.rotate_speed) - \
	bm->game.diry * sin(-bm->game.rotate_speed);
	bm->game.diry = bm->game.old * sin(-bm->game.rotate_speed) + \
	bm->game.diry * cos(-bm->game.rotate_speed);
	bm->game.old2 = bm->game.planex;
	bm->game.planex = bm->game.planex * cos(-bm->game.rotate_speed) - \
	bm->game.planey * sin(-bm->game.rotate_speed);
	bm->game.planey = bm->game.old2 * sin(-bm->game.rotate_speed) + \
	bm->game.planey * cos(-bm->game.rotate_speed);
}
