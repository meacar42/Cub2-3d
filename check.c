/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:40:38 by beyildir          #+#    #+#             */
/*   Updated: 2023/08/08 11:37:43 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_arg(t_data *bm, char *str)
{
	if (!ft_strncmp(str, "WE", 2) && bm->map.we != NULL)
		error();
	else if (!ft_strncmp(str, "EA", 2) && bm->map.ea != NULL)
		error();
	else if (!ft_strncmp(str, "SO", 2) && bm->map.so != NULL)
		error();
	else if (!ft_strncmp(str, "NO", 2) && bm->map.no != NULL)
		error();
	else if (!ft_strncmp(str, "F", 1) && bm->map.f != NULL)
		error();
	else if (!ft_strncmp(str, "C", 1) && bm->map.c != NULL)
		error();
}

void	map_checker(t_data *bm)
{
	bm->i = -1;
	while (bm->map.map_l + 2 > ++(bm->i))
	{
		bm->j = -1;
		while (bm->map.map_w + 2 > ++(bm->j))
		{
			if (bm->map.i_map[bm->i][bm->j] == 0
				|| bm->map.i_map[bm->i][bm->j] == S
				|| bm->map.i_map[bm->i][bm->j] == W
				|| bm->map.i_map[bm->i][bm->j] == E
				|| bm->map.i_map[bm->i][bm->j] == N)
				check_wall_player(bm);
			if (bm->map.i_map[bm->i][bm->j] == S
				|| bm->map.i_map[bm->i][bm->j] == W
				|| bm->map.i_map[bm->i][bm->j] == E
				|| bm->map.i_map[bm->i][bm->j] == N)
				find_loc_player(bm);
		}
	}
	if (bm->counter != 1)
		error();
}

int	check_var(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] == ' ' && tmp[i])
		i++;
	if (tmp[i] == '\0' || tmp[i] == '\n')
		return (2);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		if (tmp[i] == '1' || tmp[i] == '0' || tmp[i] == 'N' || tmp[i] == 'S'
			|| tmp[i] == 'W' || tmp[i] == 'E' || tmp[i] == ' ')
			i++;
		else
			return (0);
	}
	if (tmp[i] == '\0')
		return (3);
	else if (i != 0)
		return (1);
	else
		return (2);
}

void	check_map(t_data *bm)
{
	bm->map.map[bm->i] = NULL;
	bm->i = 0;
	bm->j = 0;
	bm->map.map_l = 0;
	while (bm->map.map[bm->i] && bm->map.map_l == 0)
	{
		if (check_var(bm->map.map[bm->i]) == 0)
			error();
		else if (check_var(bm->map.map[bm->i]) == 1)
			bm->i++;
		else if (check_var(bm->map.map[bm->i]) == 2)
			bm->map.map_l = bm->i;
		else if (check_var(bm->map.map[bm->i]) == 3)
			bm->map.map_l = ++(bm->i);
	}
	if (bm->map.map_l == 0)
		bm->map.map_l = bm->i;
	while (bm->map.map[bm->i])
	{
		check_tmp(bm->map.map[bm->i]);
		bm->i++;
	}
}

int	check_wall(char *tmp)
{
	int	i;

	i = 0;
	if (tmp)
	{
		while (tmp[i])
		{
			if (tmp[i] == '1' || tmp[i] == '0' || tmp[i] == 'N' || tmp[i] == 'S'
				|| tmp[i] == 'W' || tmp[i] == 'E')
				return (1);
			i++;
		}
	}
	return (0);
}
