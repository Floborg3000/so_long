#include "../include/so_long.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/Libft/ft_printf/ft_printf.h"
#include "../lib/Libft/libft.h"

void    open_image(t_game *game)
{
    game->textures.ground = //mlx_load_png
    game->textures.wall = 
    game->textures.collectible = 
    game->textures.exit = 
    //mlx_texture
    //delete_texture sinon leaks!!!
}

void    fill_map(t_game *game, int lines, char *map)
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