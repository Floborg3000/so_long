
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/Libft/ft_printf/ft_printf.h"
#include "../lib/Libft/libft.h"
#include "../include/so_long.h"

int ft_destroy(t_game *game)
{
    mlx_delete_image(game->mlx, game->img);
    mlx_close_window(game->mlx);
    return (0);
}



int32_t	main(int argc, char **argv)
{
    t_game game;
    
if (!argc)
return (1);
    check_map_extension("invalid_map.txt");
    game.mlx = mlx_init(500, 500, "so_long", true);
    game.img = mlx_new_image(game.mlx, 400, 400);
    
    mlx_loop(game.mlx);
    fill_map(&game, 6, argv[1]);
    mlx_terminate(game.mlx);

    return (EXIT_SUCCESS);
}
