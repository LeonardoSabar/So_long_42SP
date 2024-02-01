/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:29:25 by leobarbo          #+#    #+#             */
/*   Updated: 2024/02/01 19:41:10 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/printf/includes/ft_printf.h"
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
# define NUM_CHARACTERE 7
# define NUM_TEXTURE 5
# define NUM_IMAGES 12

# define EMPTY_MSG "Error\nEmpty map\n"
# define NOT_EXIST_MSG "Error\nMap does not exist\n"
# define RECTANGLE_MSG "Error\nMap is not a rectangle\n"
# define ELEMENTS_MSG "Error\nMap has wrongs components\n"
# define WALL_MSG "Error\nMap don't have close walls\n"
# define PARAMETERS_MSG "Error\n It requires 2 parameters\n"
# define EXTENSION_MSG "Error\nFile extension is not .ber\n"
# define NUMBER_PLAYER_MSG "Error\nMap has more or less than one player\n"
# define NUMBER_EXIT_MSG "Error\nMap has more or less than one exit\n"
# define NO_COLLECTIBLE_MSG "Error\nMap has no collectibles\n"
# define NO_PATH_MSG "Error\nMap has no valid path\n"

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
	char			**map_copy;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*scroll_image;
	mlx_image_t		*images[NUM_IMAGES];
	mlx_texture_t	*characteres[NUM_CHARACTERE];
	mlx_texture_t	*maps_textures[NUM_TEXTURE];
	mlx_texture_t	*icon;
	mlx_texture_t	*scroll_texture;
	int				collectible;
	int				width_tile;
	int				height_tile;
	int				chest_pos_x;
	int				chest_pos_y;
	int				char_pos_x;
	int				char_pos_y;
	int				last_state;
	int				moves;
	mlx_image_t		*strimage;
}	t_main;

//main.c
int		main(int argc, char **argv);
int		ft_game_init(t_main *game);
void	ft_screen_resize(t_main *game);

//validation.c
int		ft_validation_map(char **map);
int		ft_wall_check(char **map);
int		ft_check_elements(char **map);
int		ft_rectangle_map(char **map);
int		ft_empty_map(char **map);

//textures.c
void	ft_free_texture(t_main *main);
void	ft_draw_elements(t_main *game);
void	ft_draw_base_map(t_main *game);
void	ft_get_textures(t_main *game);

//images.c
void	ft_get_images(t_main *game);
void	ft_images_elements(t_main *game);
void	ft_images_character(t_main *game);

//movement.c
void	ft_movement(mlx_key_data_t keydata, void *param);
void	ft_move_up(t_main *game);
void	ft_move_down(t_main *game);
void	ft_move_left(t_main *game);
void	ft_move_right(t_main *game);

//movement2.c
void	ft_action_key(mlx_key_data_t keydata, t_main *game);
void	ft_release_key(t_main *game);
void	ft_print_moves(t_main *game);
void	ft_put_moves(t_main *game);

//exit.c
void	ft_chest_position(t_main *game);
int		ft_count_exit(char **game);
void	ft_exit_game(t_main *game);

//utils.c
void	ft_free_map(char **map);
int		*ft_size_map(char **map);
void	ft_start_pos(t_main *game);
int		ft_count_player(char **game);

//map.c
char	**ft_read_map(char *map_content);
int		ft_check_extension(char *file);

//collectibles.c
void	ft_count_collectible(t_main *game);
void	ft_pick_collectibles(t_main *game);
int		ft_zero_collectible(char **game);

//flood.c
void	ft_flood_fill(t_main *game, int x, int y);
int		ft_check_flood_fill(char **map);
int		ft_valid_path(t_main *game, char *fd);
#endif
