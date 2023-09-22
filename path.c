/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:40:14 by beyildir          #+#    #+#             */
/*   Updated: 2023/08/08 10:22:05 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	path_check(t_data *bm)
{
	if (ft_strncmp(bm->map.we, "./", 2) || \
	ft_strncmp(bm->map.so, "./", 2) || \
	ft_strncmp(bm->map.ea, "./", 2) || \
	ft_strncmp(bm->map.no, "./", 2))
		error();
	if (open(&bm->map.we[2], O_RDWR) == -1 || \
	open(&bm->map.so[2], O_RDWR) == -1 || \
	open(&bm->map.ea[2], O_RDWR) == -1 || \
	open(&bm->map.no[2], O_RDWR, 0777) == -1)
		error();
}

void	location_path_check(t_data *bm)
{
	bm->map.ea = path_ret(bm->map.ea);
	bm->map.so = path_ret(bm->map.so);
	bm->map.we = path_ret(bm->map.we);
	bm->map.no = path_ret(bm->map.no);
	bm->map.f = path_ret(bm->map.f);
	bm->map.c = path_ret(bm->map.c);
	bm->map.ea = path_ret(&bm->map.ea[2]);
	bm->map.so = path_ret(&bm->map.so[2]);
	bm->map.we = path_ret(&bm->map.we[2]);
	bm->map.no = path_ret(&bm->map.no[2]);
	bm->map.f = path_ret(&bm->map.f[1]);
	bm->map.c = path_ret(&bm->map.c[1]);
	trim_nline(bm->map.c);
	trim_nline(bm->map.f);
	trim_nline(bm->map.ea);
	trim_nline(bm->map.so);
	trim_nline(bm->map.no);
	trim_nline(bm->map.we);
	check_xpm(bm);
}

char	*path_ret(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] == ' ')
		i++;
	return (&tmp[i]);
}

void	check_xpm(t_data *bm)
{
	int	i;
	int	j;
	int	k;
	int	x;

	i = ft_strlen(bm->map.ea);
	j = ft_strlen(bm->map.no);
	k = ft_strlen(bm->map.so);
	x = ft_strlen(bm->map.we);
	if (i <= 4 || j <= 4 || k <= 4 || x <= 4)
		error();
	if (ft_strncmp(&bm->map.ea[i - 4], ".xpm", 4) || \
	ft_strncmp(&bm->map.no[j - 4], ".xpm", 4) || \
	ft_strncmp(&bm->map.so[k - 4], ".xpm", 4) || \
	ft_strncmp(&bm->map.we[x - 4], ".xpm", 4))
		error();
}
