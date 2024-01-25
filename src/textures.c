/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:41:41 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/25 08:37:16 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_main *game)
{
	game->characteres[INICIAL] = mlx_load_png("images/immobile.png");
	game->characteres[INICIAL2] = mlx_load_png("images/immobile2.png");
	game->characteres[WALK_LEFT] = mlx_load_png("images/left.png");
	game->characteres[WALK_RIGHT] = mlx_load_png("images/right.png");
	game->characteres[WALK_UP] = mlx_load_png("images/up.png");
	game->characteres[WALK_DOWN] = mlx_load_png("images/down.png");
	game->maps_textures[FLOOR] = mlx_load_png("images/grass2.png");
	game->maps_textures[WALL] = mlx_load_png("images/wall64.png");
	game->maps_textures[COLLECTIBLE] = mlx_load_png("images/21.png");
	game->maps_textures[EXIT] = mlx_load_png("images/chest1.png");
	game->maps_textures[EXIT_OPEN] = mlx_load_png("images/chest2.png");
	// game->characteres[ENEMIE] = mlx_load_png("images/18.png");
}

void	get_images(t_main *game)
{
	game->images[IMG_INICIAL] = mlx_texture_to_image(game->mlx,
		game->characteres[INICIAL]);
	game->images[IMG_INICIAL2] = mlx_texture_to_image(game->mlx,
		game->characteres[INICIAL2]);
	game->images[IMG_WALK_LEFT] = mlx_texture_to_image(game->mlx,
		game->characteres[WALK_LEFT]);
	game->images[IMG_WALK_RIGHT] = mlx_texture_to_image(game->mlx,
		game->characteres[WALK_RIGHT]);
	game->images[IMG_WALK_UP] = mlx_texture_to_image(game->mlx,
		game->characteres[WALK_UP]);
	game->images[IMG_WALK_DOWN] = mlx_texture_to_image(game->mlx,
		game->characteres[WALK_DOWN]);
	game->images[IMG_WALL] = mlx_texture_to_image(game->mlx,
		game->maps_textures[WALL]);
	game->images[IMG_FLOOR]= mlx_texture_to_image(game->mlx,
		game->maps_textures[FLOOR]);
	game->images[IMG_COLLECTIBLE] = mlx_texture_to_image(game->mlx,
		game->maps_textures[COLLECTIBLE]);
	game->images[IMG_EXIT] = mlx_texture_to_image(game->mlx,
		game->maps_textures[EXIT]);
	game->images[IMG_EXIT_OPEN] = mlx_texture_to_image(game->mlx,
		game->maps_textures[EXIT_OPEN]);
	// game->images[IMG_ENEMIE] = texture_to_image_resized(game,
	// 	game->characteres[ENEMIE]);
}
void	draw_base_map(t_main *game)
{
	int	height;
	int	width;

	height = 0;
	while (game->map[height])
	{
		width = 0;
		while (game->map[height][width])
		{
			mlx_image_to_window(game->mlx, game->images[IMG_FLOOR],
				width * game->width_tile, height * game->height_tile);
			if (game->map[height][width] == '1')
				mlx_image_to_window(game->mlx, game->images[IMG_WALL],
				width * game->width_tile, height * game->height_tile);
			if (game->map[height][width] == 'E')
				mlx_image_to_window(game->mlx, game->images[IMG_EXIT],
				width * game->width_tile, height * game->height_tile);
			width++;
		}
		height++;
	}
}

void	draw_elements(t_main *game)
{
	int	height;
	int	width;

	draw_base_map(game);
	height = 0;
	while (game->map[height])
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == 'C')
				mlx_image_to_window(game->mlx, game->images[IMG_COLLECTIBLE],
				width * game->width_tile, height * game->height_tile);
			else if (game->map[height][width] == 'P')
				mlx_image_to_window(game->mlx, game->images[IMG_INICIAL],
				width * game->width_tile, height * game->height_tile);
			width++;
		}
		height++;
	}
}
