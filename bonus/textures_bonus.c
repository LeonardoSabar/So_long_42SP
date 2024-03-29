/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:41:41 by leobarbo          #+#    #+#             */
/*   Updated: 2024/02/01 18:48:44 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_get_textures(t_main *game)
{
	game->characteres[INICIAL] = mlx_load_png("images/immobile1.png");
	game->characteres[INICIAL2] = mlx_load_png("images/immobile2.png");
	game->characteres[WALK_LEFT] = mlx_load_png("images/left.png");
	game->characteres[WALK_RIGHT] = mlx_load_png("images/right.png");
	game->characteres[WALK_UP] = mlx_load_png("images/up.png");
	game->characteres[WALK_DOWN] = mlx_load_png("images/down.png");
	game->characteres[ENEMIE] = mlx_load_png("images/enemie.png");
	game->maps_textures[WALL] = mlx_load_png("images/wall.png");
	game->maps_textures[FLOOR] = mlx_load_png("images/floor.png");
	game->maps_textures[EXIT] = mlx_load_png("images/chest1.png");
	game->maps_textures[EXIT_OPEN] = mlx_load_png("images/chest2.png");
	game->maps_textures[COLLECTIBLE] = mlx_load_png("images/key.png");
	game->icon = mlx_load_png("images/icon.png");
	game->scroll_texture = mlx_load_png("images/scroll4.png");
}

void	ft_draw_base_map(t_main *game)
{
	int	height;
	int	width;

	height = -1;
	while (game->map[++height])
	{
		width = -1;
		while (game->map[height][++width])
		{
			mlx_image_to_window(game->mlx, game->images[IMG_FLOOR],
				width * game->width_tile, height * game->height_tile);
			if (game->map[height][width] == '1')
				mlx_image_to_window(game->mlx, game->images[IMG_WALL],
					width * game->width_tile, height * game->height_tile);
			if (game->map[height][width] == 'E')
				mlx_image_to_window(game->mlx, game->images[IMG_EXIT],
					width * game->width_tile, height * game->height_tile);
			if (game->map[height][width] == 'C')
				mlx_image_to_window(game->mlx, game->images[IMG_COLLECTIBLE],
					width * game->width_tile, height * game->height_tile);
			else if (game->map[height][width] == 'V')
				mlx_image_to_window(game->mlx, game->images[IMG_ENEMIE],
					width * game->width_tile, height * game->height_tile);
		}
	}
}

void	ft_draw_elements(t_main *game)
{
	int	height;
	int	width;

	ft_draw_base_map(game);
	height = 0;
	while (game->map[height])
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == 'C')
				mlx_image_to_window(game->mlx, game->images[IMG_COLLECTIBLE],
					width * game->width_tile, height * game->height_tile);
			if (game->map[height][width] == 'P')
				mlx_image_to_window(game->mlx, game->images[IMG_INICIAL],
					width * game->width_tile, height * game->height_tile);
			width++;
		}
		height++;
	}
}

void	ft_free_texture(t_main *main)
{
	int	i;

	i = 0;
	while (i < NUM_CHARACTERE)
	{
		mlx_delete_texture(main->characteres[i]);
		i++;
	}
	i = 0;
	while (i < NUM_TEXTURE)
	{
		mlx_delete_texture(main->maps_textures[i]);
		i++;
	}
	mlx_delete_texture(main->scroll_texture);
}
