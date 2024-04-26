/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcornill <fcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:22:05 by fcornill          #+#    #+#             */
/*   Updated: 2024/04/17 13:04:43 by fcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(size_t x, size_t y, t_game *game, char **mapcpy)
{
	if (x < 0 || x >= game->col_count || y < 0 || y >= game->row_count \
	|| mapcpy[y][x] == '1')
		return ;
	if (mapcpy[y][x] == 'C')
		game->col++;
	if (mapcpy[y][x] == 'E')
		game->ex++;
	mapcpy[y][x] = '1';
	flood_fill(x + 1, y, game, mapcpy);
	flood_fill(x, y + 1, game, mapcpy);
	flood_fill(x - 1, y, game, mapcpy);
	flood_fill(x, y - 1, game, mapcpy);
}

char	**map_cpy(t_game *game, char **mapcpy)
{
	size_t	y;
	size_t	len;

	y = 0;
	while (game->map[y] != NULL && y < game->row_count)
	{
		len = ft_strlen(game->map[y]);
		mapcpy[y] = ft_calloc((len + 1), sizeof(char));
		if (!mapcpy[y])
			return (NULL);
		ft_strlcpy(mapcpy[y], game->map[y], len + 1);
		y++;
	}
	mapcpy[y] = NULL;
	return (mapcpy);
}

int	valid_path(t_game *game)
{
	size_t	y;
	size_t	x;
	char	**mapcpy;

	y = game->player_y;
	x = game->player_x;
	mapcpy = ft_calloc((game->row_count + 1), sizeof(char *));
	if (!mapcpy)
		return (0);
	map_cpy(game, mapcpy);
	pre_flood_fill(game, mapcpy);
	flood_fill(x, y, game, mapcpy);
	free_map(mapcpy);
	if (game->col == game->n_item && game->ex == game->n_exit)
	{
		ft_printf("Path ok\n");
		return (0);
	}
	else
		ft_error("Error\nNo valid path\n");
	return (0);
}

void	pre_flood_fill(t_game *game, char **mapcpy)
{
	size_t	y;
	size_t	x;

	x = 0;
	y = 0;
	while (y < game->row_count - 1)
	{
		x = 0;
		while (mapcpy[y][x] && x < ft_strlen(mapcpy[0]) - 1)
		{
			if (mapcpy[y][x] == 'E' && (!(mapcpy[y + 1][x] == '1' && mapcpy[y
						- 1][x] == '1' && mapcpy[y][x + 1] == '1' && mapcpy[y][x
						- 1] == '1')))
			{
				mapcpy[y][x] = '1';
				game->ex++;
				return ;
			}
			x++;
		}
		y++;
	}
}
