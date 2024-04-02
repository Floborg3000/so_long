//x = column, y = line

void    read_map(t_game *game, size_t line_count, char *argv)
{
    int file;
    int i;

    i = 0;
    file = open(map, O_RDWR);
    game->map = malloc((lines + 1) * sizeof(char *));
    if (game->map)
    {
        game->map[0] = get_next_line(file);
        while (i < lines)
        {
            i++;
            game->map[i] = get_next_line(file);
        }
        close(file);
    }

}



void	flood_fill(t_game *game, size_t mv_x, size_t mv_y)
{
	if (mv_x < 0 || mv_y < 0 || mv_x >= game->x || mv_y >= game->y || game->map[mv_x][mv_y] == '1' || game->map[mv_x][mv_y] == 'X')
		return ;
	if (((game->map[mv_x + 1][mv_y] == 'E') || (game->map[mv_x - 1][mv_y] == 'E')) && ((game->map[mv_x][mv_y + 1] == '1') || (game->map[mv_x][mv_y - 1] == '1')))
	       return ;	

}
