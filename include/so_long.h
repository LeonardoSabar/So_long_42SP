/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:29:25 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/25 08:37:20 by leobarbo         ###   ########.fr       */
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
# define MOVE 64
# define BUFFER_SIZE 50
# define NUM_CHARACTERE 6
# define NUM_TEXTURE 6
# define NUM_IMAGES 12

# define EMPTY_MSG "Error\nEmpty map\n"
# define RECTANGLE_MSG "Error\nMap is not a rectangle\n"
# define ELEMENTS_MSG "Error\nMap has wrongs components\n"
# define WALL_MSG "Error\nMap don't have close walls\n"
# define PARAMETERS_MSG "Error\n It requires 2 parameters\n"

enum e_characteres
{
	INICIAL = 0,
	INICIAL2,
	WALK_LEFT,
	WALK_RIGHT,
	WALK_UP,
	WALK_DOWN,
	ENEMIE,
};

enum e_maps_textures
{
	WALL = 0,
	FLOOR,
	EXIT,
	EXIT_OPEN,
	COLLECTIBLE,
};

enum e_images
{
	IMG_INICIAL = 0,
	IMG_INICIAL2,
	IMG_WALK_LEFT,
	IMG_WALK_RIGHT,
	IMG_WALK_UP,
	IMG_WALK_DOWN,
	IMG_WALL,
	IMG_FLOOR,
	IMG_EXIT,
	IMG_EXIT_OPEN,
	IMG_ENEMIE,
	IMG_COLLECTIBLE,
};

typedef struct s_main
{
	char			**map;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*images[NUM_IMAGES];
	mlx_texture_t	*characteres[NUM_CHARACTERE];
	mlx_texture_t	*maps_textures[NUM_TEXTURE];
	int				collectable;
	int				width_tile;
	int				height_tile;
	int				chest_position_x;
	int				chest_position_y;
	int				x;
	int				y;
	int				last_state;
}	t_main;

//validation.c
int	ft_validation_map(char **map);
int	ft_check_elements(char **map);
int	ft_wall_check(char **map);
int	ft_empty_map(char **map);
int	ft_rectangle_map(char **map);

//main.c
int		main(int argc, char **argv);
int		ft_game_init(t_main *game);
void	ft_screen_resize(t_main *game);


void	movement(mlx_key_data_t keydata, void* param);
char	**read_map(char *map_content);
int		check_extension(char *file);
void	get_textures(t_main *game);
void	draw_base_map(t_main *game);
void	draw_elements(t_main *game);
void	get_images(t_main *game);
void	start_pos(t_main *game);
void	count_collectible(t_main *game);
void	pick_collectibles(t_main *game);

#endif
