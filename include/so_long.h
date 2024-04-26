/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcornill <fcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:34:24 by fcornill          #+#    #+#             */
/*   Updated: 2024/04/17 15:39:37 by fcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../include/so_long.h"
# include "../lib/Libft/ft_printf/ft_printf.h"
# include "../lib/Libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <fcntl.h>
# include <inttypes.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_texture
{
	mlx_texture_t	*ground_t;
	mlx_texture_t	*wall_t;
	mlx_texture_t	*collectible_t;
	mlx_texture_t	*exit_t;
	mlx_texture_t	*player_t;
}					t_texture;

typedef struct s_image
{
	mlx_image_t		*ground;
	mlx_image_t		*wall;
	mlx_image_t		*exit;
	mlx_image_t		*collectible;
	mlx_image_t		*player;
}					t_image;

typedef struct s_game
{
	mlx_t			*mlx;
	size_t			n_item;
	size_t			n_exit;
	size_t			n_player;
	size_t			player_y;
	size_t			player_x;
	size_t			col;
	size_t			ex;
	size_t			row_count;
	size_t			col_count;
	char			**map;
	t_texture		texture;
	t_image			old_image;
	t_image			image;
	int				left;
	size_t			move_count;
}					t_game;

void				init_structure(t_game *game);
void				check_map_extension(char *str);
void				is_rectangle(char **map, size_t row_count, t_game *game);
void				is_wall(char **map, size_t row_count);
void				check_map_content(char **map, size_t row_count,
						t_game *game);
void				count_item(t_game *game, char c);
char				**read_map(char *map_file, size_t row_count);
char				**map_cpy(t_game *game, char **mapcpy);
size_t				get_row_count(char *map);
void				pre_flood_fill(t_game *game, char **mapcpy);
void				flood_fill(size_t x, size_t y, t_game *game, char **mapcpy);
int					valid_path(t_game *game);
void				free_map(char **map);
void				keyboard_move(mlx_key_data_t keycode, void *param);
void				load_image(t_game *game);
mlx_image_t			*open_image(mlx_t *mlx, char *path);
void				image_to_window(t_game *game, size_t y, size_t x);
void				render_map(t_game *game);
void				set_window_size(t_game *game);
void				ft_move_up(t_game *game);
void				ft_move_down(t_game *game);
void				ft_move_left(t_game *game);
void				ft_move_right(t_game *game);
void				update_window(void *param);
size_t				win_and_exit(t_game *game, char c);
void				ft_error(char *str);
void				clean_image(t_game *game);

#endif