/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcornill <fcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:40:30 by fcornill          #+#    #+#             */
/*   Updated: 2024/04/17 19:12:04 by fcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	size_t	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

size_t	win_and_exit(t_game *game, char c)
{
	if (c == 'C')
		game->n_item--;
	else if (c == 'E' && game->n_item != 0)
	{
		ft_printf("There is some cheese left!\n");
		return (1);
	}
	else if (c == 'E' && game->n_item == 0)
	{
		mlx_close_window(game->mlx);
		ft_printf("Congratulations! You won in %d moves!\n", game->move_count++);
		exit(0);
	}
	return (0);
}

void	set_window_size(t_game *game)
{
	int32_t	screen_with;
	int32_t	screen_height;

	screen_with = 0;
	screen_height = 0;
	mlx_get_monitor_size(0, &screen_with, &screen_height);
	mlx_set_window_limit(game->mlx, -1, screen_with, -1, screen_height);
	if ((game->col_count > 2560 / 40) || (game->row_count > (1440 / 40) - 1))
		ft_error("Error\nMap is too big!\n");
}

void	clean_image(t_game *game)
{
	mlx_delete_image(game->mlx, game->old_image.ground);
	mlx_delete_image(game->mlx, game->old_image.wall);
	mlx_delete_image(game->mlx, game->old_image.exit);
	mlx_delete_image(game->mlx, game->old_image.player);
}
