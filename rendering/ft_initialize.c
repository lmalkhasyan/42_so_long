/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:32:19 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/01 20:59:41 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize(t_program *s)
{
	s->mlx = mlx_init();
	if (s->mlx == NULL)
	{
		ft_free_matrix(&(s->map.matrix));
		ft_exit_error("Can't do initialization");
	}
	s->win = mlx_new_window(s->mlx, s->map.width * TEXTURE_Y,
			s->map.height * TEXTURE_X, "so_long");
	if (s->win == NULL)
	{
		ft_free_matrix(&(s->map.matrix));
		ft_exit_error("Can't Creat Window");
	}
	mlx_hook(s->win, 17, 0, ft_destroy_window, s);
}
