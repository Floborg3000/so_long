/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcornill <fcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:32:56 by fcornill          #+#    #+#             */
/*   Updated: 2024/04/17 15:11:27 by fcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_structure(t_game *game)
{
	game->n_item = 0;
	game->n_exit = 0;
	game->n_player = 0;
	game->player_y = 0;
	game->player_x = 0;
	game->col = 0;
	game->ex = 0;
	game->left = 0;
	game->row_count = 0;
	game->col_count = 0;
	game->move_count = 0;
}

void	check_map(t_game *game)
{
	if (!game)
		exit(EXIT_FAILURE);
	check_map_content(game->map, game->row_count, game);
	is_rectangle(game->map, game->row_count, game);
	is_wall(game->map, game->row_count);
	valid_path(game);
}

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error("Error\nInvalid number of arguments\n");
	init_structure(&game);
	check_map_extension(argv[1]);
	game.row_count = get_row_count(argv[1]);
	game.map = read_map(argv[1], game.row_count);
	game.col_count = ft_strlen(game.map[0]);
	if (ft_strlen(game.map[0]) == 0)
		ft_error("Error\nEmpty file!\n");
	check_map(&game);
	game.mlx = mlx_init(game.col_count * 40, game.row_count * 40, "so_long",
			false);
	if (!game.mlx)
		exit(EXIT_FAILURE);
	set_window_size(&game);
	load_image(&game);
	mlx_loop_hook(game.mlx, &update_window, &game);
	mlx_key_hook(game.mlx, &keyboard_move, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
