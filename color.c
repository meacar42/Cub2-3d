/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:40:35 by beyildir          #+#    #+#             */
/*   Updated: 2023/08/08 10:27:11 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_val_check(t_data *bm)
{
	int	i;

	i = 0;
	while (bm->map.c[i])
	{
		if (((bm->map.c[i] == ' ' || bm->map.c[i] == ',')
				|| (bm->map.c[i] >= '0' && bm->map.c[i] <= '9'))
			&& bm->map.c[i])
			i++;
		else
			error();
	}
	i = 0;
	while (bm->map.f[i])
	{
		if (((bm->map.f[i] == ' ' || bm->map.f[i] == ',')
				|| (bm->map.f[i] >= '0' && bm->map.f[i] <= '9'))
			&& bm->map.f[i])
			i++;
		else
			error();
	}
}

void	comma_check(t_data *bm)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (bm->map.f[++i])
	{
		if (bm->map.f[i] == ',')
			count++;
	}
	if (count != 2)
		error();
	i = -1;
	count = 0;
	while (bm->map.c[++i])
	{
		if (bm->map.c[i] == ',')
			count++;
	}
	if (count != 2)
		error();
}

void	color_extra_check(t_data *bm)
{
	int	i;

	i = 0;
	bm->tmpf = ft_split(bm->map.f, ',');
	bm->tmpc = ft_split(bm->map.c, ',');
	while (bm->tmpf[i])
		i++;
	if (i != 3)
		error();
	i = 0;
	while (bm->tmpc[i])
		i++;
	if (i != 3)
		error();
}

int	color_max_min(int i)
{
	if (i < 0 || i > 255)
		error();
	return (i);
}

void	color_set(t_data *bm)
{
	color_val_check(bm);
	comma_check(bm);
	color_extra_check(bm);
	bm->floor.r = color_max_min(ft_atoi(bm->tmpf[0]));
	bm->floor.g = color_max_min(ft_atoi(bm->tmpf[1]));
	bm->floor.b = color_max_min(ft_atoi(bm->tmpf[2]));
	bm->sky.r = color_max_min(ft_atoi(bm->tmpc[0]));
	bm->sky.g = color_max_min(ft_atoi(bm->tmpc[1]));
	bm->sky.b = color_max_min(ft_atoi(bm->tmpc[2]));
}
