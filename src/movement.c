/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:07:23 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/30 15:13:49 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	ft_move_up(t_main *game)
{
	if (game->map[game->char_pos_y / 64 - 1][game->char_pos_x / 64] != '1')
	{
		game->char_pos_y -= MOVE;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_UP]);
		game->last_state = WALK_RIGHT;
		game->moves++;
	}
}

void	ft_move_down(t_main *game)
{
	if (game->map[game->char_pos_y / 64 + 1][game->char_pos_x / 64] != '1')
	{
		game->char_pos_y += MOVE;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image
			(game->mlx, game->characteres[WALK_DOWN]);
		game->last_state = WALK_RIGHT;
		game->moves++;
	}
}

void	ft_move_left(t_main *game)
{
	if (game->map[game->char_pos_y / 64][game->char_pos_x / 64 - 1] != '1')
	{

		game->char_pos_x -= MOVE;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image
			(game->mlx, game->characteres[WALK_LEFT]);
		game->last_state = WALK_LEFT;
		game->moves++;
	}
}

void	ft_move_right(t_main *game)
{

	if (game->map[game->char_pos_y / 64][(game->char_pos_x / 64) + 1] != '1')
	{
		game->char_pos_x += MOVE;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_texture_to_image
			(game->mlx, game->characteres[WALK_RIGHT]);
		game->last_state = WALK_RIGHT;
		game->moves++;
	}
}

void	ft_movement(mlx_key_data_t keydata, void *param)
{
	t_main	*game;

	game = (t_main *)param;
	ft_exit_game(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		return ;
	}
	ft_pick_collectibles(game);
	if (keydata.action == MLX_PRESS)
		ft_action_key(keydata, game);
	else if (keydata.action == MLX_RELEASE)
		ft_release_key(game);
	if (game->collectible == 0)
	{
		mlx_delete_image(game->mlx, game->images[IMG_EXIT]);
		ft_chest_position(game);
		mlx_image_to_window(game->mlx, game->images[IMG_EXIT_OPEN],
			game->chest_pos_x, game->chest_pos_y);
		game->collectible = -1;
	}
}
