/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:07:10 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/03 18:21:31 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_program	s;

	if (argc == 2)
	{
		ft_map(&s.map, argv[1]);
		ft_initialize(&s);
		s.moves = 0;
		ft_fill_textures(&(s.imgs), s.mlx);
		ft_draw_map(&s);
		mlx_hook(s.win, 2, 0, ft_key_press, &s);
		mlx_loop(s.mlx);
	}
	ft_exit_error("No Valid Argument \nusage: ./so_long map_file.ber");
	return (0);
}
