/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcornill <fcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:09:38 by fcornill          #+#    #+#             */
/*   Updated: 2024/04/17 14:23:19 by fcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	get_row_count(char *map)
{
	int		fd;
	size_t	row_count;
	char	*line;

	row_count = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nCan not open the file!\n");
	line = get_next_line(fd);
	while (line)
	{
		row_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (row_count);
}

char	**read_map(char *map_file, size_t row_count)
{
	char	**map;
	size_t	i;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nCan not open the file!\n");
	map = ft_calloc((row_count + 1), sizeof(char *));
	if (!map)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < row_count)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}
