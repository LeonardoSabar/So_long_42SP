/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:07:23 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/18 19:08:26 by leobarbo         ###   ########.fr       */
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
		if (DIR_W || DIR_UP)
		{
			game->y -= MOVE;
			game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_LEFT]);
		}
		else if (DIR_S || DIR_DOWN)
		{
			game->y += MOVE;
			game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_RIGHT]);
		}
		else if (DIR_A || DIR_LEFT)
		{
			game->x -= MOVE;
			game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_UP]);
		}
		else if (DIR_D || DIR_RIGHT)
		{
			game->x += MOVE;
			game->img = mlx_texture_to_image(game->mlx, game->characteres[WALK_DOWN]);
		}
		// mlx_resize_image(game->img, 32, 32);
		// mlx_image_to_window(game->mlx, game->img, game->x, game->y);
	}
}
