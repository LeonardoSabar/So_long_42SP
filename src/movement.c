/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:07:23 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/19 16:03:05 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	move_up(t_main *game)
{
	if (game->map[game->y / 64 - 1][game->x / 64] != '1')
	{
		game->y -= MOVE;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_UP]);
	}
}

void	move_left(t_main *game)
{
	if (game->map[game->y / 64][game->x / 64 - 1] != '1')
	{
		game->x -= MOVE;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_LEFT]);
	}
}

void	move_down(t_main *game)
{
	if (game->map[game->y / 64 + 1][game->x / 64] != '1')
	{
		game->y += MOVE;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_DOWN]);
	}
}

void	move_right(t_main *game)
{
	if (game->map[game->y / 64][game->x / 64 + 1] != '1')
	{
		game->x += MOVE;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_RIGHT]);
	}
}

void	movement(mlx_key_data_t keydata, void* param)
{
	t_main* game;

	game = (t_main *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);

	if (keydata.action == MLX_PRESS)
	{
		mlx_delete_image(game->mlx, game->img);
		mlx_delete_image(game->mlx, game->images[IMG_INICIAL]);
		game->img = mlx_texture_to_image(game->mlx, game->characteres[INICIAL]);
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_up(game);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_down(game);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_left(game);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_right(game);
		mlx_resize_image(game->img, 64, 64);
		mlx_image_to_window(game->mlx, game->img, game->x, game->y);
	}
}
