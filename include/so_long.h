/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:29:25 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/16 20:13:25 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/printf/include/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <memory.h>

# define WIDTH 1280
# define HEIGHT 720
# define FALSE 1
# define TRUE 0
# define MOVE 100
# define BUFFER 10000
# define NUM_CHARACTERE 5
# define NUM_TEXTURE 4

# define EMPTY_MSG "Error\nEmpty map\n"
# define RECTANGLE_MSG "Error\nMap is not a rectangle\n"
# define ELEMENTS_MSG "Error\nMap has wrongs components\n"
# define WALL_MSG "Error\nMap don't have close walls\n"
# define PARAMETERS_MSG "Error\n It requires 2 parameters\n"


# define DIR_W keydata.key == MLX_KEY_W
# define DIR_S keydata.key == MLX_KEY_S
# define DIR_A keydata.key == MLX_KEY_A
# define DIR_D keydata.key == MLX_KEY_D

# define DIR_UP keydata.key == MLX_KEY_UP
# define DIR_DOWN keydata.key == MLX_KEY_DOWN
# define DIR_LEFT keydata.key == MLX_KEY_LEFT
# define DIR_RIGHT keydata.key == MLX_KEY_RIGHT

enum e_characteres
{
	INCIAL = 0,
	WALK_LEFT,
	WALK_RIGHT,
	WALK_UP,
	WALK_DOWN
};

enum e_maps_textures
{
	WALL = 0,
	FLOOR,
	EXIT,
	COLLECTIBLE,
};

typedef struct s_main
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*background;
	mlx_image_t		*front;
	mlx_texture_t	*charactere[NUM_CHARACTERE];
	mlx_texture_t	*enemie[NUM_CHARACTERE];
	mlx_texture_t	*maps_textures[NUM_TEXTURE];
	int				x;
	int				y;
}	t_main;

typedef struct s_game
{
	char	**map;
	t_main	*main;
	mlx_t*	mlx;
}	t_game;


void	movement(mlx_key_data_t keydata, void* param);
int		main(int argc, char **argv);
int		check_map(char **map);
char	**read_map(char *map_content);
int		check_extension(char *file);
int		wrong_map(char **map);
int		wall_map(char **map);
size_t	ft_strlen(const char *s);
void	get_textures(t_game *game);
int		game_init(t_game *game);

#endif
