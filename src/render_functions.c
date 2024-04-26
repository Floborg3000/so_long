/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcornill <fcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:52:18 by fcornill          #+#    #+#             */
/*   Updated: 2024/04/17 14:19:14 by fcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_image(t_game *game)
{
	game->image.ground = open_image(game->mlx, "./assets/ground.png");
	game->image.wall = open_image(game->mlx, "./assets/wall.png");
	game->image.collectible = open_image(game->mlx, "./assets/collectible.png");
	if (game->left == 0)
		game->image.player = open_image(game->mlx, "./assets/rat.png");
	else
		game->image.player = open_image(game->mlx, "./assets/r_rat.png");
	if (game->n_item == 0)
		game->image.exit = open_image(game->mlx, "./assets/exit_open.png");
	else
		game->image.exit = open_image(game->mlx, "./assets/exit_close.png");
}

mlx_image_t	*open_image(mlx_t *mlx, char *path)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	if (!path)
		ft_error("Error\nCan not find image!\n");
	texture = mlx_load_png(path);
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

void	image_to_window(t_game *game, size_t y, size_t x)
{
	if (y != 0 || x != 0)
		mlx_image_to_window(game->mlx, game->image.ground, x * 40, y * 40);
	if (game->map[y][x] == '1')
		mlx_image_to_window(game->mlx, game->image.wall, x * 40, y * 40);
	else if (game->map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->image.collectible, x * 40, y * 40);
	else if (game->map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->image.exit, x * 40, y * 40);
	else if (game->map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->image.player, x * 40, y * 40);
	mlx_set_window_size(game->mlx, (game->col_count - 1) * 40, game->row_count
		* 40);
}

void	render_map(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	clean_image(game);
	game->old_image = game->image;
	load_image(game);
	while (y < game->row_count)
	{
		x = 0;
		while (x < game->col_count - 1)
		{
			image_to_window(game, y, x);
			x++;
		}
		y++;
	}
}

void	update_window(void *param)
{
	t_game	*game;

	game = param;
	render_map(game);
}
