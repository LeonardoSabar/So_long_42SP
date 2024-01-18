/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:41:41 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/18 18:31:23 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_main *game)
{
	// game->characteres[INICIAL] = mlx_load_png("images/cha.png");
	// game->characteres[WALK_LEFT] = mlx_load_png("images/cha1.png");
	// game->characteres[WALK_RIGHT] = mlx_load_png("images/cha2.png");
	// game->characteres[WALK_UP] = mlx_load_png("images/cha3.png");
	// game->characteres[WALK_DOWN] = mlx_load_png("images/cha4.png");
	game->maps_textures[FLOOR] = mlx_load_png("images/floor.png");
	game->maps_textures[WALL] = mlx_load_png("images/wall.png");
}
void	get_images(t_main *game)
{
	// game->images[IMG_INICIAL] = mlx_texture_to_image(game->mlx,
	// 	game->characteres[INICIAL]);
	// game->images[IMG_WALK_LEFT] = mlx_texture_to_image(game->mlx,
	// 	game->characteres[WALK_LEFT]);
	// game->images[IMG_WALK_RIGHT] = mlx_texture_to_image(game->mlx,
	// 	game->characteres[WALK_RIGHT]);
	// game->images[IMG_WALK_UP] = mlx_texture_to_image(game->mlx,
	// 	game->characteres[WALK_UP]);
	// game->images[IMG_WALK_DOWN] = mlx_texture_to_image(game->mlx,
	// 	game->characteres[WALK_DOWN]);
	game->images[IMG_WALL] = mlx_texture_to_image(game->mlx,
		game->characteres[WALL]);
	game->images[IMG_FLOOR]= mlx_texture_to_image(game->mlx,
		game->characteres[FLOOR]);
	// game->main->images[IMG_EXIT] = mlx_texture_to_image(game->mlx,
	// 	game->main->characteres[EXIT]);
	// game->main->images[IMG_ENEMIE] = mlx_texture_to_image(game->mlx,
	// 	game->main->characteres[ENEMIE]);
}
void	draw_floor(t_main *game)
{
	int	height;
	int	width;

	height = 0;
	while (game->map[height])
	{
		width = 0;
		while (game->map[height][width])
		{
			mlx_image_to_window(game->mlx, game->images[IMG_FLOOR], height * 32, width * 32);
			if (game->map[height][width] == '1')
			{
				mlx_image_to_window(game->mlx, game->images[IMG_WALL], height * 32, width * 32);
				width++;
			}
		}
		height++;
	}
}
