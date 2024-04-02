#include <stdio.h>

void	check_map_content(char **map, size_t line_count)
{
	size_t	x;
	size_t	y;
	int	n_item;
	int	n_exit;
	int	n_player;

	x = 0;
	y = 0;
	n_collectible = 0;
	n_exit = 0;
	n_player = 0;
	while (x < line_count - 1)
	{
		y = 0;
		while (map[x][y] && y < ft_strlen(map[0]) - 2)
		{
			if (map[x][y] != '1' && map[x][y] != '0' && map[x][y] != 'E' && map[x][y] != 'C' && map[x][y] != 'P')
				ft_printf("Error\nMap contain invalid characters!\n");
			//verifier si E == 1 , P == 1 && C != 0 envoyer ces donner dans la struc ou ecrire une autre fonction pour checker car fonction trop longue
			//afficher un message d'erreur
			if (map[x][y] == 'C')
				n_item++;
			if (map[x][y] == 'E')
				n_exit++;
			if (map[x][y] == 'P')
				n_player++;
			y++;
		}
		x++;
	}
}


size_t	get_map_size(char **map)
{
	int	fd;
	size_t	line_count;

	line_count = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_printf("Error\nOpen file\n");
	while (get_next_line(fd))
		line_count++;
	if (line_count == 0)
		ft_print("Error\nEmpty map's file\n");
	close(fd);
	return (line_count);
}


void	is_wall(char **map, size_t line_count)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < line_count)
	{
		y = 0;
		if (x == 0 || x == line_count - 1)
		{
			while (map[x][y] && y < ft_strlen(map[0]) - 1)     //  map[x][y] empeche y de depasser les limite de la carte et provoquer un deboredement de memoire
			{
				if (map[x][y] != '1')
					ft_printf("Error\nMap is not valid\n");
				y++;
			}
		}
		y = 0;
		while (map[x][y] && y < ft_strlen(map[0]) - 1)
		{
			if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1') //-2 pour tenir compte du \n ou \0
				ft_printf("Error\nMap is not valid\n");
			y++;
		}
		x++;
	}
}





