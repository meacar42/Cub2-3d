/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:03:55 by beyildir          #+#    #+#             */
/*   Updated: 2023/08/08 10:34:12 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_1(int key, t_data *bm)
{
	if (key == ESC)
		close_window(bm);
	if (key == KW)
		bm->key.w_key = 1;
	if (key == KA)
		bm->key.a_key = 1;
	if (key == KS)
		bm->key.s_key = 1;
	if (key == KD)
		bm->key.d_key = 1;
	if (key == LEFT)
		bm->key.cam_left = 1;
	if (key == RIGHT)
		bm->key.cam_right = 1;
	return (0);
}

int	move_2(int key, t_data *bm)
{
	if (key == ESC)
		close_window(bm);
	if (key == KW)
		bm->key.w_key = 0;
	if (key == KA)
		bm->key.a_key = 0;
	if (key == KS)
		bm->key.s_key = 0;
	if (key == KD)
		bm->key.d_key = 0;
	if (key == LEFT)
		bm->key.cam_left = 0;
	if (key == RIGHT)
		bm->key.cam_right = 0;
	return (0);
}

int	close_window(t_data *bm)
{
	mlx_destroy_window(bm->game.mlx, bm->game.win);
	exit(0);
	return (0);
}
