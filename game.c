/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:40:25 by beyildir          #+#    #+#             */
/*   Updated: 2023/08/08 11:19:34 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_val(t_data *bm)
{
	bm->game.posx = 22;
	bm->game.posy = 12;
	bm->game.move_speed = 0.03;
	bm->key.w_key = 0;
	bm->key.a_key = 0;
	bm->key.s_key = 0;
	bm->key.d_key = 0;
	bm->game.m_w = 0;
	bm->key.cam_left = 0;
	bm->key.cam_right = 0;
	bm->key.map_key = 0;
	bm->game.rotate_speed = 0.032;
	get_color(bm);
}

void	game_image(t_data *bm)
{
	bm->map.n_o = mlx_xpm_file_to_image(bm->game.mlx, bm->map.no, \
	&bm->game.m_w, &bm->game.m_w);
	bm->map.s_o = mlx_xpm_file_to_image(bm->game.mlx, bm->map.so, \
	&bm->game.m_w, &bm->game.m_w);
	bm->map.e_a = mlx_xpm_file_to_image(bm->game.mlx, bm->map.ea, \
	&bm->game.m_w, &bm->game.m_w);
	bm->map.w_e = mlx_xpm_file_to_image(bm->game.mlx, bm->map.we, \
	&bm->game.m_w, &bm->game.m_w);
	if (bm->map.w_e == NULL || bm->map.e_a == NULL || bm->map.s_o == NULL \
	|| bm->map.n_o == NULL)
		error();
	bm->map.i_no = (int *)mlx_get_data_addr(bm->map.n_o, \
	&bm->game.bpp, &bm->game.sl, &bm->game.end);
	bm->map.i_so = (int *)mlx_get_data_addr(bm->map.s_o, \
	&bm->game.bpp, &bm->game.sl, &bm->game.end);
	bm->map.i_ea = (int *)mlx_get_data_addr(bm->map.e_a, \
	&bm->game.bpp, &bm->game.sl, &bm->game.end);
	bm->map.i_we = (int *)mlx_get_data_addr(bm->map.w_e, \
	&bm->game.bpp, &bm->game.sl, &bm->game.end);
	if (bm->map.i_no == NULL || bm->map.i_so == NULL || bm->map.i_ea == NULL \
	|| bm->map.i_we == NULL)
		error();
}

void	start(t_data *bm)
{
	start_val(bm);
	bm->game.mlx = mlx_init();
	bm->game.win = mlx_new_window(bm->game.mlx, WIDTH, HEIGHT, "cub3D");
	bm->game.img = mlx_new_image(bm->game.mlx, WIDTH, HEIGHT);
	bm->game.addr = (int *)mlx_get_data_addr(bm->game.img, \
	&bm->game.bpp, &bm->game.sl, &bm->game.end);
	game_image(bm);
	mlx_hook(bm->game.win, 17, 0, close_window, bm);
	mlx_loop_hook(bm->game.mlx, screen_fill, bm);
	mlx_hook(bm->game.win, 3, 0, move_2, bm);
	mlx_hook(bm->game.win, 2, 0, move_1, bm);
	mlx_loop(bm->game.mlx);
}

int	screen_fill(t_data *bm)
{
	int	width;

	mlx_clear_window(bm->game.mlx, bm->game.win);
	color_painting(bm);
	width = 0;
	while (width < WIDTH)
	{
		set_data(bm, width);
		wallcheck(bm);
		hitcheck(bm);
		get_dist(bm);
		set_image_values(bm);
		draw_image(bm, width);
		width++;
	}
	mlx_put_image_to_window(bm->game.mlx, bm->game.win, bm->game.img, 0, 0);
	move_func(bm);
	return (0);
}
