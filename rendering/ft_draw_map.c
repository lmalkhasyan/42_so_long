/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:58:19 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/01 20:58:42 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_program *s, int i, int j)
{
	if (s->map.matrix[i][j] == 'C')
		mlx_put_image_to_window(s->mlx, s->win, s->imgs.collect,
			j * TEXTURE_X, i * TEXTURE_Y);
	if (s->map.matrix[i][j] == 'E')
		mlx_put_image_to_window(s->mlx, s->win, s->imgs.exit,
			j * TEXTURE_X, i * TEXTURE_Y);
	if (s->map.matrix[i][j] == '1')
		mlx_put_image_to_window(s->mlx, s->win, s->imgs.wall,
			j * TEXTURE_X, i * TEXTURE_Y);
	if (s->map.matrix[i][j] == '0')
		mlx_put_image_to_window(s->mlx, s->win, s->imgs.floor,
			j * TEXTURE_X, i * TEXTURE_Y);
	if (s->map.matrix[i][j] == 'P')
	{
		(s->imgs.player.x) = j;
		(s->imgs.player.y) = i;
		mlx_put_image_to_window(s->mlx, s->win, s->imgs.player.ptr,
			j * TEXTURE_X, i * TEXTURE_Y);
		s->map.matrix[i][j] = '0';
	}
}

void	ft_draw_map(t_program *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->map.matrix[i])
	{
		j = 0;
		while (s->map.matrix[i][j])
		{
			ft_put_image(s, i, j);
			j++;
		}
		i++;
	}
}
