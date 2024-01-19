/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:41:41 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/19 11:19:54 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_main *game)
{
	game->characteres[INICIAL] = mlx_load_png("images/duck.png");
	game->characteres[WALK_LEFT] = mlx_load_png("images/1cha64.png");
	game->characteres[WALK_RIGHT] = mlx_load_png("images/2cha64.png");
	game->characteres[WALK_UP] = mlx_load_png("images/3cha64.png");
	game->characteres[WALK_DOWN] = mlx_load_png("images/4cha64.png");
	game->maps_textures[FLOOR] = mlx_load_png("images/floor64.png");
	game->maps_textures[WALL] = mlx_load_png("images/wall64.png");
	game->maps_textures[COLLECTIBLE] = mlx_load_png("images/colle64.png");
	game->maps_textures[EXIT] = mlx_load_png("images/Water.png");
	// game->characteres[ENEMIE] = mlx_load_png("images/18.png");
}
void	get_images(t_main *game)
{
	game->images[IMG_INICIAL] = mlx_texture_to_image(game->mlx,
		game->characteres[INICIAL]);
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
	// game->images[IMG_ENEMIE] = mlx_texture_to_image(game->mlx,
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
			mlx_image_to_window(game->mlx, game->images[IMG_FLOOR], width * 64, height * 64);
			if (game->map[height][width] == '1')
				mlx_image_to_window(game->mlx, game->images[IMG_WALL], width * 64, height * 64);
			if (game->map[height][width] == 'E')
				mlx_image_to_window(game->mlx, game->images[IMG_EXIT], width * 64, height * 64);
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
				mlx_image_to_window(game->mlx, game->images[IMG_COLLECTIBLE], width * 64, height * 64);
			else if (game->map[height][width] == 'P')
				mlx_image_to_window(game->mlx, game->images[IMG_INICIAL], width * 64, height * 64);
			width++;
		}
		height++;
	}
}
