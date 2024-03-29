/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:46:45 by leobarbo          #+#    #+#             */
/*   Updated: 2024/02/01 18:47:51 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_images_character(t_main *game)
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
	game->images[IMG_ENEMIE] = mlx_texture_to_image(game->mlx,
			game->characteres[ENEMIE]);
}

void	ft_images_elements(t_main *game)
{
	game->images[IMG_WALL] = mlx_texture_to_image(game->mlx,
			game->maps_textures[WALL]);
	game->images[IMG_FLOOR] = mlx_texture_to_image(game->mlx,
			game->maps_textures[FLOOR]);
	game->images[IMG_COLLECTIBLE] = mlx_texture_to_image(game->mlx,
			game->maps_textures[COLLECTIBLE]);
	game->images[IMG_EXIT] = mlx_texture_to_image(game->mlx,
			game->maps_textures[EXIT]);
	game->images[IMG_EXIT_OPEN] = mlx_texture_to_image(game->mlx,
			game->maps_textures[EXIT_OPEN]);
}

void	ft_get_images(t_main *game)
{
	ft_images_character(game);
	ft_images_elements(game);
	game->scroll_image = mlx_texture_to_image(game->mlx,
			game->scroll_texture);
}
