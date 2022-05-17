/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalkhas <lmalkhas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:16:09 by lmalkhas          #+#    #+#             */
/*   Updated: 2022/05/02 16:42:45 by lmalkhas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

# define MAP_0 "./textures/0.xpm"
# define MAP_C "./textures/C.xpm"
# define MAP_E "./textures/E1.xpm"
# define MAP_W "./textures/W.xpm"
# define MAP_P "./textures/PD.xpm"
# define TEXTURE_X 32
# define TEXTURE_Y 32

/* player and his cordinates */
typedef struct s_player
{
	void	*ptr;
	int		x;
	int		y;
}				t_player;
/* All textures */
typedef struct s_img
{
	void		*collect;
	void		*exit;
	void		*wall;
	void		*floor;
	t_player	player;
}				t_img;
/* Map */
typedef struct s_map
{
	int		width;
	int		height;
	int		collect;
	char	**matrix;
}				t_map;
/* All program */
typedef struct s_program
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	imgs;
	int		moves;
}				t_program;
/* Printf */
int		ft_printf(const char *format, ...);
int		ft_check_format(const char *format, va_list *args);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int n, unsigned int base, int type);
int		ft_putnbr_unsigned(unsigned long long n, unsigned int base, int type);
int		ft_putptr(void *ptr);

/* GET_NEXT_LINE */
# define BUFFER_SIZE 100

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char const *s2);

/* additional functions */
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/* Exit with Error */
void	ft_exit_error(char *str);
/* Functions for Free Matrix and Arrary */
void	ft_free_array(char **arr);
void	ft_free_matrix(char ***matrix);

/* Check Valid map */
void	ft_map(t_map *map, const char *mappath);
void	ft_check_map(t_map *map);
void	ft_check_wall(t_map *map);
void	ft_check_numbers(char **matrix, int *collect);
void	ft_mapsize(char **map, int *width, int *height);

/* Initialization to mlx lib */
void	ft_initialize(t_program *s);

/* Event Functions */
int		ft_key_press(int keycode, t_program *s);
int		ft_destroy_window(t_program *s);

/* Fill Textures */
void	ft_fill_textures(t_img *imgs, void *mlx);

/* fill one texture to window */
void	ft_fill_player(t_program *s, int i, int j);
void	ft_fill_floor(t_program *s, int i, int j);
void	ft_fill_exit(t_program *s, int i, int j);

/* Render Map */
void	ft_draw_map(t_program *s);
void	ft_put_image(t_program *s, int i, int j);

/* Moves */
void	ft_move_up(t_program *s);
void	ft_move_down(t_program *s);
void	ft_move_left(t_program *s);
void	ft_move_right(t_program *s);
#endif
