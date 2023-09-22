/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:40:28 by beyildir          #+#    #+#             */
/*   Updated: 2023/08/08 11:38:05 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	filecheck(t_data *bm, char **ag)
{
	bm->map.map = malloc(sizeof(char *) * map_count(ag));
	bm->fd = open(ag[1], O_RDWR, 0777);
	if (bm->fd == -1)
		error();
	bm->tmp = get_next_line(bm->fd);
	while (bm->tmp)
	{
		check_arg(bm, bm->tmp);
		if (set_arg(bm, bm->tmp))
		{
			if (check_wall(bm->tmp))
				break ;
			check_tmp(bm->tmp);
			free(bm->tmp);
		}
		bm->tmp = get_next_line(bm->fd);
	}
	set_check_args(bm, 1);
	if (!bm->tmp)
		error();
	while (bm->tmp)
	{
		bm->map.map[(bm->i)++] = bm->tmp;
		bm->tmp = get_next_line(bm->fd);
	}
}

int	set_check_args(t_data *bm, int flag)
{
	if (flag == 0)
	{
		bm->map.we = NULL;
		bm->map.ea = NULL;
		bm->map.so = NULL;
		bm->map.no = NULL;
		bm->map.f = NULL;
		bm->map.c = NULL;
		bm->i = 0;
		bm->j = 0;
		bm->counter = 0;
	}
	else if (flag == 1)
	{
		if (bm->map.we != NULL && bm->map.ea != NULL && bm->map.no != NULL
			&& bm->map.so != NULL && bm->map.f != NULL && bm->map.c != NULL)
			return (1);
		else
			error();
	}
	return (0);
}

int	set_arg(t_data *bm, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!ft_strncmp(&str[i], "WE ", 3))
		bm->map.we = str;
	else if (!ft_strncmp(&str[i], "EA ", 3))
		bm->map.ea = str;
	else if (!ft_strncmp(&str[i], "SO ", 3))
		bm->map.so = str;
	else if (!ft_strncmp(&str[i], "NO ", 3))
		bm->map.no = str;
	else if (!ft_strncmp(&str[i], "F ", 2))
		bm->map.f = str;
	else if (!ft_strncmp(&str[i], "C ", 2))
		bm->map.c = str;
	else
		return (1);
	return (0);
}
