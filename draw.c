/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:03:49 by beyildir          #+#    #+#             */
/*   Updated: 2023/08/08 10:24:37 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_image(t_data *bm, int i)
{
	int	a;

	a = bm->game.draw_start;
	while (a < bm->game.draw_end)
	{
		bm->game.my = (int)bm->game.pixel_nbr & (bm->game.m_w - 1);
		bm->game.pixel_nbr += bm->game.pixel_cal;
		if (bm->game.raydirx > 0 && bm->game.side != 1)
			bm->game.colour = bm->map.i_so[bm->game.m_w * bm->game.my
				+ bm->game.mx];
		else if (bm->game.raydirx < 0 && bm->game.side != 1)
			bm->game.colour = bm->map.i_no[bm->game.m_w * bm->game.my
				+ bm->game.mx];
		else if ((bm->game.raydirx <= 2 && bm->game.raydiry >= 0)
			&& bm->game.side == 1)
			bm->game.colour = bm->map.i_ea[bm->game.m_w * bm->game.my
				+ bm->game.mx];
		else
			bm->game.colour = bm->map.i_we[bm->game.m_w * bm->game.my
				+ bm->game.mx];
		bm->game.addr[a * WIDTH + i] = bm->game.colour;
		a++;
	}
}

void	color_painting(t_data *bm)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				bm->game.addr[i * WIDTH + j] = bm->sky.t;
			else
				bm->game.addr[i * WIDTH + j] = bm->floor.t;
			j++;
		}
		i++;
	}
}

void	get_color(t_data *bm)
{
	int	total;

	total = 0;
	total += (bm->floor.r * 65536);
	total += (bm->floor.g * 256);
	total += (bm->floor.b * 1);
	bm->floor.t = total;
	total = 0;
	total += (bm->sky.r * 65536);
	total += (bm->sky.g * 256);
	total += (bm->sky.b * 1);
	bm->sky.t = total;
}
