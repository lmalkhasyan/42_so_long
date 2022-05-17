/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:13:56 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/02 19:15:04 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_left(t_program *s)
{
	if (s->map.matrix[s->imgs.player.y][s->imgs.player.x - 1] == '0')
	{
		ft_fill_player(s, s->imgs.player.y, s->imgs.player.x - 1);
		ft_fill_floor(s, s->imgs.player.y, s->imgs.player.x);
		s->imgs.player.x--;
	}
	else if (s->map.matrix[s->imgs.player.y][s->imgs.player.x - 1] == 'C')
	{
		ft_fill_player(s, s->imgs.player.y, s->imgs.player.x - 1);
		ft_fill_floor(s, s->imgs.player.y, s->imgs.player.x);
		s->map.matrix[s->imgs.player.y][s->imgs.player.x - 1] = '0';
		s->map.collect--;
		s->imgs.player.x--;
	}
	else if (s->map.matrix[s->imgs.player.y][s->imgs.player.x - 1] == 'E')
	{
		if (s->map.collect)
			return ;
		ft_fill_player(s, s->imgs.player.y, s->imgs.player.x - 1);
		ft_fill_floor(s, s->imgs.player.y, s->imgs.player.x);
		ft_destroy_window(s);
	}
}
