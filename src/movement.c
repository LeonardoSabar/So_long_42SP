/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:07:23 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/22 20:06:16 by leobarbo         ###   ########.fr       */
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

/////////////////////////////////////////////////////////////////
// ARRUMA ESSA MERDA AQUI EM BAIXO

typedef struct s_point
{
	int x;
	int y;
} t_point;


t_point	posicao_bau(t_main *game)
{
	int	idx;
	int	odx;
	t_point	point;

	point.x = -1;
	point.y = -1;
	idx = 0;
	while (game->map[idx])
	{
		odx = 0;
		while (game->map[idx][odx])
		{
			if (game->map[idx][odx] == 'E')
			{
				point.x = odx * 64;
				point.y = idx * 64;
				return point;
			}
			odx++;
		}
		idx++;
	}
	return (point);
}

///////////////////////////////////////////////////////////////

void	movement(mlx_key_data_t keydata, void* param)
{
	t_main* game;

	game = (t_main *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);

	pick_collectibles(game);
	if (keydata.action == MLX_PRESS)
	{
		// mlx_delete_image(game->mlx, game->img);
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
		// game->images[EXIT] = game->images[IMG_EXIT_OPEN];

		t_point point = posicao_bau(game);

		mlx_image_to_window(game->mlx, game->images[IMG_EXIT_OPEN], point.x, point.y);


		game->collectable = -1;
	}
}
