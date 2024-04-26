/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcornill <fcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:16:11 by fcornill          #+#    #+#             */
/*   Updated: 2024/04/17 14:20:29 by fcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move_up(t_game *game)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < game->row_count)
	{
		x = -1;
		while (++x < game->col_count)
		{
			if (game->map[y][x] == 'P')
			{
				if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C'
					|| game->map[y - 1][x] == 'E')
				{
					if (win_and_exit(game, game->map[y - 1][x]) == 1)
						return ;
					game->map[y - 1][x] = 'P';
					game->map[y][x] = '0';
					game->move_count++;
					ft_printf("%d\n", game->move_count);
					return ;
				}
			}
		}
	}
}

void	ft_move_down(t_game *game)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < game->row_count)
	{
		x = -1;
		while (++x < game->col_count)
		{
			if (game->map[y][x] == 'P')
			{
				if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C'
					|| game->map[y + 1][x] == 'E')
				{
					if (win_and_exit(game, game->map[y + 1][x]) == 1)
						return ;
					game->map[y + 1][x] = 'P';
					game->map[y][x] = '0';
					game->move_count++;
					ft_printf("%d\n", game->move_count);
					return ;
				}
			}
		}
	}
}

void	ft_move_left(t_game *game)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < game->row_count)
	{
		x = -1;
		while (++x < game->col_count)
		{
			if (game->map[y][x] == 'P')
			{
				if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C'
					|| game->map[y][x - 1] == 'E')
				{
					if (win_and_exit(game, game->map[y][x - 1]) == 1)
						return ;
					game->map[y][x - 1] = 'P';
					game->map[y][x] = '0';
					game->move_count++;
					ft_printf("%d\n", game->move_count);
					return ;
				}
			}
		}
	}
}

void	ft_move_right(t_game *game)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (++y < game->row_count)
	{
		x = -1;
		while (++x < game->col_count)
		{
			if (game->map[y][x] == 'P')
			{
				if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C'
					|| game->map[y][x + 1] == 'E')
				{
					if (win_and_exit(game, game->map[y][x + 1]) == 1)
						return ;
					game->map[y][x + 1] = 'P';
					game->map[y][x] = '0';
					game->move_count++;
					ft_printf("%d\n", game->move_count);
					return ;
				}
			}
		}
	}
}

void	keyboard_move(mlx_key_data_t keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode.action == MLX_PRESS)
	{
		if (keycode.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (keycode.key == MLX_KEY_W || keycode.key == MLX_KEY_UP)
			ft_move_up(game);
		if (keycode.key == MLX_KEY_S || keycode.key == MLX_KEY_DOWN)
			ft_move_down(game);
		if (keycode.key == MLX_KEY_A || keycode.key == MLX_KEY_LEFT)
		{
			game->left = 1;
			ft_move_left(game);
		}
		if (keycode.key == MLX_KEY_D || keycode.key == MLX_KEY_RIGHT)
		{
			game->left = 0;
			ft_move_right(game);
		}
	}
}
