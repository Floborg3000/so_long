#include "../include/so_long.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/Libft/ft_printf/ft_printf.h"

int check_map_extension(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    i--;
    if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b' && str[i - 3] == '.')
        return (1);
    else
         ft_printf("Error\nOnly files with the .ber extension are accepted!"); 
    return (0);
}

int is_rectangle(t_game *game)
{
    int i;
    int x;
    int len;

    i = 0;
    len  = ft_strlen(game->map[0]);
    while (game->map[i])
    {
        x = ft_strlen(game->map[i]);
        if (x != len)
            ft_printf("Error\nMap lines don't have the same length!\n"); //peut etre ecriire une fonction pour gerer erreur et message
        i++;
    }
    if (game->lines == game->columns)
        ft_printf("Error\nMap need to be a rectangle!\n");
    return (0);
}



