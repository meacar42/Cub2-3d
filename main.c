/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:39:48 by beyildir          #+#    #+#             */
/*   Updated: 2023/08/08 10:15:37 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_file(t_data *bm, char **ag)
{
	check_cub(ag);
	set_check_args(bm, 0);
	filecheck(bm, ag);
	check_map(bm);
	i_map_set(bm);
	map_convert(bm);
	map_checker(bm);
	location_path_check(bm);
	path_check(bm);
	color_set(bm);
}

int	main(int ac, char **ag)
{
	t_data	bm;

	if (ac == 2)
	{
		set_file(&bm, ag);
		start(&bm);
	}
	else
		printf("Error\n");
	return (1);
}
