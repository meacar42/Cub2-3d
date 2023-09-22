/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:40:19 by beyildir          #+#    #+#             */
/*   Updated: 2023/08/08 10:29:55 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	i_map_set(t_data *bm)
{
	bm->i = 0;
	bm->map.map_w = 0;
	bm->map.i_map = malloc(sizeof(int *) * (bm->map.map_l + 3));
	while (bm->i < bm->map.map_l)
	{
		if (ft_wmaplen(bm->map.map[bm->i]) > bm->map.map_w)
			bm->map.map_w = ft_wmaplen(bm->map.map[bm->i]);
		(bm->i)++;
	}
	bm->i = -1;
	while (++(bm->i) < (bm->map.map_l + 2))
	{
		bm->j = 0;
		bm->map.i_map[bm->i] = malloc(sizeof(int) * (bm->map.map_w + 2));
		if (bm->i == 0)
		{
			while (bm->j < (bm->map.map_w + 2))
				bm->map.i_map[bm->i][(bm->j)++] = 2;
		}
		else if (bm->i == bm->map.map_l + 1)
		{
			while (bm->j < (bm->map.map_w + 2))
				bm->map.i_map[bm->i][(bm->j)++] = 2;
		}
	}
}

void	map_convert(t_data *bm)
{
	int	i;
	int	j;

	i = -1;
	while (++i < bm->map.map_l)
	{
		j = 0;
		if (j == 0)
			bm->map.i_map[i + 1][0] = 2;
		while (bm->map.map[i][j] && bm->map.map[i][j] != '\n')
		{
			if (bm->map.map[i][j] == ' ')
				bm->map.i_map[i + 1][j + 1] = 2;
			else
				bm->map.i_map[i + 1][j + 1] = bm->map.map[i][j] - 48;
			j++;
		}
		while (j < bm->map.map_w + 1)
		{
			bm->map.i_map[i + 1][j + 1] = 2;
			j++;
		}
	}
	bm->map.i_map[i + 2] = NULL;
}

int	map_count(char **ag)
{
	int		fd;
	char	*tmp;
	int		count;

	count = 0;
	fd = open(ag[1], O_RDWR, 0777);
	if (fd == -1)
		error();
	tmp = get_next_line(fd);
	while (tmp)
	{
		count++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	check_wall_player(t_data *bm)
{
	if ((bm->map.i_map[bm->i + 1][bm->j] == 2 || bm->map.i_map[bm->i
			- 1][bm->j] == 2 || bm->map.i_map[bm->i][bm->j + 1] == 2
			|| bm->map.i_map[bm->i][bm->j - 1] == 2))
		error();
	return (0);
}

void	find_loc_player(t_data *bm)
{
	(bm->counter)++;
	if (bm->map.i_map[bm->i][bm->j] == W)
	{
		bm->game.dirx = -1;
		bm->game.planey = -0.66;
	}
	else if (bm->map.i_map[bm->i][bm->j] == E)
	{
		bm->game.dirx = 1;
		bm->game.planey = 0.66;
	}
	else if (bm->map.i_map[bm->i][bm->j] == N)
	{
		bm->game.diry = -1;
		bm->game.planex = 0.66;
	}
	else if (bm->map.i_map[bm->i][bm->j] == S)
	{
		bm->game.diry = 1;
		bm->game.planex = -0.66;
	}
	bm->game.x_loc_p = bm->j - 0.5;
	bm->game.y_loc_p = bm->i - 0.5;
	bm->game.player_direction = bm->map.map[bm->i - 1][bm->j - 1];
}
