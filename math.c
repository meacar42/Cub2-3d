/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:03:58 by beyildir          #+#    #+#             */
/*   Updated: 2023/08/08 10:30:21 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_image_values(t_data *bm)
{
	if (bm->game.side == 0)
		bm->game.wallx = bm->game.y_loc_p + bm->game.wall_dist
			* bm->game.raydiry;
	else
		bm->game.wallx = bm->game.x_loc_p + bm->game.wall_dist
			* bm->game.raydirx;
	bm->game.wallx -= floor(bm->game.wallx);
	bm->game.mx = (int)(bm->game.wallx * 64);
	if (bm->game.side == 0 && bm->game.raydirx > 0)
		bm->game.mx = 64 - bm->game.mx - 1;
	if (bm->game.side == 1 && bm->game.raydiry < 0)
		bm->game.mx = 64 - bm->game.mx - 1;
	bm->game.pixel_cal = 1.0 * 64 / bm->game.line_height;
	bm->game.pixel_nbr = (bm->game.draw_start - HEIGHT / 2 \
	+ bm->game.line_height / 2) * bm->game.pixel_cal;
}

void	get_dist(t_data *bm)
{
	if (bm->game.side == 0)
		bm->game.wall_dist = bm->game.sidedistx - bm->game.deltadistx;
	else
		bm->game.wall_dist = bm->game.sidedisty - bm->game.deltadisty;
	bm->game.line_height = (int)(HEIGHT / bm->game.wall_dist);
	bm->game.draw_start = -bm->game.line_height / 2 + HEIGHT / 2;
	if (bm->game.draw_start < 0)
		bm->game.draw_start = 0;
	bm->game.draw_end = bm->game.line_height / 2 + HEIGHT / 2;
	if (bm->game.draw_end >= HEIGHT)
		bm->game.draw_end = HEIGHT - 1;
}

void	hitcheck(t_data *bm)
{
	while (bm->game.hit == 0)
	{
		if (bm->game.sidedistx < bm->game.sidedisty)
		{
			bm->game.sidedistx += bm->game.deltadistx;
			bm->game.mapx += bm->game.stepx;
			bm->game.side = 0;
		}
		else
		{
			bm->game.sidedisty += bm->game.deltadisty;
			bm->game.mapy += bm->game.stepy;
			bm->game.side = 1;
		}
		if (bm->map.map[bm->game.mapy][bm->game.mapx] == '1')
			bm->game.hit = 1;
	}
}

void	wallcheck(t_data *bm)
{
	if (bm->game.raydirx < 0)
	{
		bm->game.stepx = -1;
		bm->game.sidedistx = (bm->game.x_loc_p - bm->game.mapx)
			* bm->game.deltadistx;
	}
	else
	{
		bm->game.stepx = 1;
		bm->game.sidedistx = (bm->game.mapx + 1.0 - bm->game.x_loc_p)
			* bm->game.deltadistx;
	}
	if (bm->game.raydiry < 0)
	{
		bm->game.stepy = -1;
		bm->game.sidedisty = (bm->game.y_loc_p - bm->game.mapy)
			* bm->game.deltadisty;
	}
	else
	{
		bm->game.stepy = 1;
		bm->game.sidedisty = (bm->game.mapy + 1.0 - bm->game.y_loc_p)
			* bm->game.deltadisty;
	}
}

void	set_data(t_data *bm, int width)
{
	bm->game.camerax = (2 * width / (double)WIDTH - 1);
	bm->game.raydirx = bm->game.dirx + bm->game.planex * bm->game.camerax;
	bm->game.raydiry = bm->game.diry + bm->game.planey * bm->game.camerax;
	bm->game.mapx = (int)bm->game.x_loc_p;
	bm->game.mapy = (int)bm->game.y_loc_p;
	bm->game.deltadistx = fabs(1 / bm->game.raydirx);
	bm->game.deltadisty = fabs(1 / bm->game.raydiry);
	bm->game.hit = 0;
}
