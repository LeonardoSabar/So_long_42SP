/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:07:23 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/25 08:27:11 by leobarbo         ###   ########.fr       */
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
		game->last_state = WALK_RIGHT;
	}
}

void	move_down(t_main *game)
{
	if (game->map[game->y / 64 + 1][game->x / 64] != '1')
	{
		game->y += MOVE;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_DOWN]);
		game->last_state = WALK_RIGHT;
	}
}

void	move_left(t_main *game)
{
	if (game->map[game->y / 64][game->x / 64 - 1] != '1')
	{
		game->x -= MOVE;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_LEFT]);
		game->last_state = WALK_LEFT;
	}
}

void	move_right(t_main *game)
{
	if (game->map[game->y / 64][(game->x / 64) + 1] != '1')
	{
		game->x += MOVE;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_RIGHT]);
		game->last_state = WALK_RIGHT;
	}
}

void	chest_position(t_main *game)
{
	int	idx;
	int	odx;

	game->chest_position_x = -1;
	game->chest_position_y = -1;
	idx = 0;
	while (game->map[idx])
	{
		odx = 0;
		while (game->map[idx][odx])
		{
			if (game->map[idx][odx] == 'E')
			{
				game->chest_position_x = odx * 64;
				game->chest_position_y = idx * 64;
				return ;
			}
			odx++;
		}
		idx++;
	}
}

void	movement(mlx_key_data_t keydata, void* param)
{
	t_main* game;

	game = (t_main *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);

	pick_collectibles(game);
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
		mlx_image_to_window(game->mlx, game->img, game->x, game->y);
	}
	else if
		(keydata.action == MLX_RELEASE)
	{
		mlx_delete_image(game->mlx, game->img);
		if (game->last_state == WALK_LEFT)
			game->img = mlx_texture_to_image(game->mlx, game->characteres[INICIAL2]);
		else
			game->img = mlx_texture_to_image(game->mlx, game->characteres[INICIAL]);
		mlx_image_to_window(game->mlx, game->img, game->x, game->y);
	}
	if (game->collectable == 0)
	{
		mlx_delete_image(game->mlx, game->images[IMG_EXIT]);
		chest_position(game);
		mlx_image_to_window(game->mlx, game->images[IMG_EXIT_OPEN], game->chest_position_x , game->chest_position_y);
		game->collectable = -1;
	}
}
