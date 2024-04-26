/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcornill <fcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:59:45 by fcornill          #+#    #+#             */
/*   Updated: 2024/04/17 14:52:08 by fcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_extension(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (!(str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b' && \
	str[i - 3] == '.'))
		ft_error("Error\nOnly files with the .ber extension are accepted!\n");
}

void	is_rectangle(char **map, size_t row_count, t_game *game)
{
	size_t	i;

	i = 0;
	while (i < row_count - 1)
	{
		if (ft_strlen(map[i]) != game->col_count)
			ft_error("Error\nMap lines don't have the same length!\n");
		i++;
	}
	if (row_count == game->col_count - 1)
		ft_error("Error\nMap need to be a rectangle!\n");
}

void	is_wall(char **map, size_t row_count)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	while (map[0][x] != '\n' && map[0][x] != '\0')
	{
		if (map[0][x] != '1' || map[row_count - 1][x] != '1')
			ft_error("Error\nMap is not valid\n");
		x++;
	}
	while (y < row_count)
	{
		if (map[y][0] != '1' || map[y][ft_strlen(map[y]) - 2] != '1')
			ft_error("Error\nMap is not valid\n");
		y++;
	}
}

void	check_map_content(char **map, size_t row_count, t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < row_count - 1)
	{
		x = 0;
		while (map[y][x] && x < ft_strlen(map[0]) - 1)
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'E' \
				&& map[y][x] != 'C' && map[y][x] != 'P')
				ft_error("Error\nMap contain invalid characters!\n");
			if (map[y][x] == 'P')
			{
				game->player_y = y;
				game->player_x = x;
			}
			count_item(game, map[y][x]);
			x++;
		}
		y++;
	}
	if (game->n_item < 1 || game->n_exit != 1 || game->n_player != 1)
		ft_error("Error\nInvalid map !!!\n");
}

void	count_item(t_game *game, char c)
{
	if (c == 'C')
		game->n_item++;
	else if (c == 'E')
		game->n_exit++;
	else if (c == 'P')
		game->n_player++;
}
