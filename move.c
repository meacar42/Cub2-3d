/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:40:16 by beyildir          #+#    #+#             */
/*   Updated: 2023/08/08 10:24:03 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_func(t_data *bm)
{
	move_forward(bm);
	if (bm->key.a_key)
		move_left(bm);
	if (bm->key.cam_left)
		cam_left(bm);
	if (bm->key.d_key)
		move_right(bm);
	if (bm->key.cam_right)
		cam_right(bm);
}

void	move_backward(t_data *bm)
{
	if (bm->map.map[(int)(bm->game.y_loc_p)][(int)(bm->game.x_loc_p - \
	bm->game.dirx * bm->game.move_speed)] == '0' || \
	bm->map.map[(int)(bm->game.y_loc_p)][(int)(bm->game.x_loc_p - \
	bm->game.dirx * bm->game.move_speed)] == bm->game.player_direction)
		bm->game.x_loc_p -= bm->game.dirx * bm->game.move_speed;
	if (bm->map.map[(int)(bm->game.y_loc_p - bm->game.diry * \
	bm->game.move_speed)][(int)bm->game.x_loc_p] == '0' || \
	bm->map.map[(int)(bm->game.y_loc_p - bm->game.diry * \
	bm->game.move_speed)][(int)bm->game.x_loc_p] == bm->game.player_direction)
		bm->game.y_loc_p -= bm->game.diry * bm->game.move_speed;
}

void	move_forward(t_data *bm)
{
	if (bm->key.w_key)
	{
		if (bm->map.map[(int)(bm->game.y_loc_p)][(int)(bm->game.x_loc_p + \
		bm->game.dirx * bm->game.move_speed)] == '0' || \
		bm->map.map[(int)(bm->game.y_loc_p)][(int)(bm->game.x_loc_p + \
		bm->game.dirx * bm->game.move_speed)] == bm->game.player_direction)
			bm->game.x_loc_p += bm->game.dirx * bm->game.move_speed;
		if (bm->map.map[(int)(bm->game.y_loc_p + bm->game.diry * \
		bm->game.move_speed)][(int)bm->game.x_loc_p] == '0' || \
		bm->map.map[(int)(bm->game.y_loc_p + bm->game.diry * \
		bm->game.move_speed)][(int)bm->game.x_loc_p] \
		== bm->game.player_direction)
			bm->game.y_loc_p += bm->game.diry * bm->game.move_speed;
	}
	else if (bm->key.s_key)
		move_backward(bm);
}

void	move_left(t_data *bm)
{
	if (bm->map.map[(int)bm->game.y_loc_p][(int)(bm->game.x_loc_p \
	- bm->game.planex * bm->game.move_speed)] == '0' || \
	bm->map.map[(int)bm->game.y_loc_p][(int)(bm->game.x_loc_p - \
	bm->game.planex * bm->game.move_speed)] == bm->game.player_direction)
		bm->game.x_loc_p -= bm->game.planex * bm->game.move_speed;
	if (bm->map.map[(int)(bm->game.y_loc_p \
	- bm->game.planey * bm->game.move_speed)][(int)bm->game.x_loc_p] == '0' || \
	bm->map.map[(int)(bm->game.y_loc_p - bm->game.planey * \
	bm->game.move_speed)][(int)bm->game.x_loc_p] == bm->game.player_direction)
		bm->game.y_loc_p -= bm->game.planey * bm->game.move_speed;
}

void	move_right(t_data *bm)
{
	if (bm->map.map[(int)bm->game.y_loc_p][(int)(bm->game.x_loc_p + \
	bm->game.planex * bm->game.move_speed)] == '0' || \
	bm->map.map[(int)bm->game.y_loc_p][(int)(bm->game.x_loc_p + bm->game.planex \
	* bm->game.move_speed)] == bm->game.player_direction)
		bm->game.x_loc_p += bm->game.planex * bm->game.move_speed;
	if (bm->map.map[(int)(bm->game.y_loc_p + bm->game.planey * \
	bm->game.move_speed)][(int)bm->game.x_loc_p] == '0' || \
	bm->map.map[(int)(bm->game.y_loc_p + bm->game.planey * \
	bm->game.move_speed)][(int)bm->game.x_loc_p] == bm->game.player_direction)
		bm->game.y_loc_p += bm->game.planey * bm->game.move_speed;
}
