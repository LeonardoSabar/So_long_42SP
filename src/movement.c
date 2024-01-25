/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:07:23 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/25 18:34:57 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	ft_move_up(t_main *game)
{
	if (game->map[game->y / 64 - 1][game->x / 64] != '1')
	{
		game->y -= MOVE;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_UP]);
		game->last_state = WALK_RIGHT;
	}
}

void	ft_move_down(t_main *game)
{
	if (game->map[game->y / 64 + 1][game->x / 64] != '1')
	{
		game->y += MOVE;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image
			(game->mlx, game->characteres[WALK_DOWN]);
		game->last_state = WALK_RIGHT;
	}
}

void	ft_move_left(t_main *game)
{
	if (game->map[game->y / 64][game->x / 64 - 1] != '1')
	{
		game->x -= MOVE;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image
			(game->mlx, game->characteres[WALK_LEFT]);
		game->last_state = WALK_LEFT;
	}
}

void	ft_move_right(t_main *game)
{
	if (game->map[game->y / 64][(game->x / 64) + 1] != '1')
	{
		game->x += MOVE;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image
			(game->mlx, game->characteres[WALK_RIGHT]);
		game->last_state = WALK_RIGHT;
	}
}

void	ft_movement(mlx_key_data_t keydata, void *param)
{
	t_main	*game;

	game = (t_main *)param;
	// mlx_put_string(game->mlx, "MOVEMENTS: ", 0, 0);
	ft_exit_game(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	ft_pick_collectibles(game);
	if (keydata.action == MLX_PRESS)
		ft_action_key(keydata, game);
	else if (keydata.action == MLX_RELEASE)
		ft_release_key(game);
	if (game->collectable == 0)
	{
		mlx_delete_image(game->mlx, game->images[IMG_EXIT]);
		ft_chest_position(game);
		mlx_image_to_window(game->mlx, game->images[IMG_EXIT_OPEN],
			game->chest_position_x, game->chest_position_y);
		game->collectable = -1;
	}
}
