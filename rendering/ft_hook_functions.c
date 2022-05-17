/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:48:27 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/03 19:23:45 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy_window(t_program *s)
{
	ft_free_matrix(&(s->map.matrix));
	mlx_destroy_window(s->mlx, s->win);
	mlx_destroy_image(s->mlx, s->imgs.collect);
	mlx_destroy_image(s->mlx, s->imgs.exit);
	mlx_destroy_image(s->mlx, s->imgs.wall);
	mlx_destroy_image(s->mlx, s->imgs.floor);
	mlx_destroy_image(s->mlx, s->imgs.player.ptr);
	exit(EXIT_SUCCESS);
}

static void	ft_check_key(int keycode, t_program *s)
{
	char	c;

	if (keycode == 0)
	{
		c = s->map.matrix[s->imgs.player.y][s->imgs.player.x - 1];
		if (c == '0' || c == 'C' || (c == 'E' && s->map.collect == 0))
			printf("Moves : %d\n", ++s->moves);
		ft_move_left(s);
	}
	if (keycode == 1)
	{
		c = s->map.matrix[s->imgs.player.y + 1][s->imgs.player.x];
		if (c == '0' || c == 'C' || (c == 'E' && s->map.collect == 0))
			printf("Moves : %d\n", ++s->moves);
		ft_move_down(s);
	}
	if (keycode == 2)
	{
		c = s->map.matrix[s->imgs.player.y][s->imgs.player.x + 1];
		if (c == '0' || c == 'C' || (c == 'E' && s->map.collect == 0))
			printf("Moves : %d\n", ++s->moves);
		ft_move_right(s);
	}
}

int	ft_key_press(int keycode, t_program *s)
{
	char	c;

	if (keycode == 53)
		ft_destroy_window(s);
	ft_check_key(keycode, s);
	if (keycode == 13)
	{
		c = s->map.matrix[s->imgs.player.y - 1][s->imgs.player.x];
		if (c == '0' || c == 'C' || (c == 'E' && s->map.collect == 0))
			printf("Moves : %d\n", ++s->moves);
		ft_move_up(s);
	}
	return (0);
}
