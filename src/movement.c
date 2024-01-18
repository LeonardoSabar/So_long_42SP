/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:07:23 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/18 14:14:23 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	movement(mlx_key_data_t keydata, void* param)
{
	t_game* game;

	game = (t_game *)param;

	if (keydata.action == MLX_PRESS)
	{
		mlx_delete_image(game->mlx, game->main->img);
		game->main->img = mlx_texture_to_image(game->mlx, game->main->characteres[INICIAL]);
		if (DIR_W || DIR_UP)
		{
			game->main->y -= MOVE;
			game->main->img = mlx_texture_to_image(game->mlx, game->main->characteres[WALK_LEFT]);
		}
		else if (DIR_S || DIR_DOWN)
		{
			game->main->y += MOVE;
			game->main->img = mlx_texture_to_image(game->mlx, game->main->characteres[WALK_RIGHT]);
		}
		else if (DIR_A || DIR_LEFT)
		{
			game->main->x -= MOVE;
			game->main->img = mlx_texture_to_image(game->mlx, game->main->characteres[WALK_UP]);
		}
		else if (DIR_D || DIR_RIGHT)
		{
			game->main->x += MOVE;
			game->main->img = mlx_texture_to_image(game->mlx, game->main->characteres[WALK_DOWN]);
		}
		mlx_resize_image(game->main->img, 100, 100);
		mlx_image_to_window(game->mlx, game->main->img, game->main->x, game->main->y);
	}
}
