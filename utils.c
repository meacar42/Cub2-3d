/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:40:09 by beyildir          #+#    #+#             */
/*   Updated: 2023/08/08 10:37:13 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_cub(char **ag)
{
	int	i;

	i = ft_strlen(ag[1]);
	if (i <= 4)
		error();
	if (ft_strncmp(&ag[1][i - 4], ".cub", 4))
		error();
}

int	ft_wmaplen(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	return (i);
}

void	check_tmp(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			i++;
		else
			error();
	}
}

void	trim_nline(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		tmp[i] = '\0';
}

void	error(void)
{
	printf("Error\n");
	exit(1);
}
