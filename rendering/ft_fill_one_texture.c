/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_one_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:20:34 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/02 15:07:56 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_player(t_program *s, int i, int j)
{
	mlx_put_image_to_window(s->mlx, s->win, s->imgs.player.ptr,
		j * TEXTURE_X, i * TEXTURE_Y);
}

void	ft_fill_floor(t_program *s, int i, int j)
{
	mlx_put_image_to_window(s->mlx, s->win, s->imgs.floor,
		j * TEXTURE_X, i * TEXTURE_Y);
}

void	ft_fill_exit(t_program *s, int i, int j)
{
	mlx_put_image_to_window(s->mlx, s->win, s->imgs.exit,
		j * TEXTURE_X, i * TEXTURE_Y);
}
