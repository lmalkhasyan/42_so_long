/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:42:42 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/01 17:37:47 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Checking map collectible, exit and player */
void	ft_check_numbers(char **m, int *collect)
{
	int	i;
	int	j;
	int	e_p[2];

	e_p[0] = 0;
	e_p[1] = 0;
	i = -1;
	while (m[++i])
	{
		j = -1;
		while (m[i][++j])
		{
			if ((m[i][j] != 'C') && (m[i][j] != 'P') &&
				(m[i][j] != 'E') && (m[i][j] != '1') && (m[i][j] != '0'))
				ft_exit_error("No correct symbol in MAP!");
			if (m[i][j] == 'C')
				(*collect)++;
			else if (m[i][j] == 'E')
				e_p[0]++;
			else if (m[i][j] == 'P')
				e_p[1]++;
		}
	}
	if ((*collect) < 1 || e_p[0] < 1 || e_p[1] != 1)
		ft_exit_error("Map symbol count Error!");
}

/* check map walls */
void	ft_check_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (i == 0 && map->matrix[i][j] != '1')
				ft_exit_error("The map not closed/surrounded by walls");
			else if (j == 0 && map->matrix[i][j] != '1')
				ft_exit_error("The map not closed/surrounded by walls");
			else if (i == map->height - 1 && map->matrix[i][j] != '1')
				ft_exit_error("The map not closed/surrounded by walls");
			else if ((j == map->width - 1 && map->matrix[i][j] != '1') ||
				map->matrix[i][map->width] != '\0' )
				ft_exit_error("The map not closed/surrounded by walls");
			j++;
		}
		i++;
	}
}

/* checking all map */
void	ft_check_map(t_map *map)
{
	map->height = 0;
	while (&(map->matrix[map->height][0]) != NULL)
		map->height++;
	map->width = 0;
	while (map->matrix[0][map->width] != '\0')
		map->width++;
	if (map->height <= 0 || map->width <= 0)
		ft_exit_error("Not a Valid MAP!");
	ft_check_wall(map);
	map->collect = 0;
	ft_check_numbers(map->matrix, &(map->collect));
}
