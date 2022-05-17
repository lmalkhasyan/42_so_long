/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:37:43 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/01 17:01:35 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map(t_map *map, const char *mappath)
{
	char	*line;
	int		fd;
	char	*str;

	str = NULL;
	if (ft_strncmp(".ber", (mappath + (ft_strlen(mappath) - 4)), 4) != 0)
		ft_exit_error("Map format is not *.ber");
	fd = open(mappath, O_RDONLY);
	if (fd == -1)
		ft_exit_error("Cant Open MAP");
	line = "1";
	while (line != NULL)
	{
		line = get_next_line(fd);
		str = ft_strjoin(str, line);
		free(line);
	}
	if (close(fd) == -1)
		ft_exit_error("Can't close Map File");
	map->matrix = ft_split(str, '\n');
	ft_free_array(&str);
	if (!(*(map->matrix)))
		ft_exit_error("cant split MAP!");
	ft_check_map(map);
}
