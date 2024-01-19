/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:07:23 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/19 12:35:39 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	movement(mlx_key_data_t keydata, void* param)
{
	t_main* game;

	game = (t_main *)param;

	if (keydata.action == MLX_PRESS)
	{
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image(game->mlx, game->characteres[INICIAL]);
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		{
			game->y -= MOVE;
			game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_LEFT]);
		}
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		{
			game->y += MOVE;
			game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_RIGHT]);
		}
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		{
			game->x -= MOVE;
			game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_UP]);
		}
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		{
			game->x += MOVE;
			game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_DOWN]);
		}
		mlx_resize_image(game->img, 64, 64);
		mlx_image_to_window(game->mlx, game->img, game->x, game->y);
	}
}
