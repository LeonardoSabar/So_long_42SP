/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:07:23 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/16 16:09:54 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	movement(mlx_key_data_t keydata, void* param)
{
	t_main* main;

	main = (t_main *)param;

	if (keydata.action == MLX_PRESS)
	{
		mlx_delete_image(main->mlx, main->img);
		main->img = mlx_texture_to_image(main->mlx, main->charactere[INCIAL]);
		if (DIR_W || DIR_UP)
		{
			main->y -= MOVE;
			main->img = mlx_texture_to_image(main->mlx, main->charactere[WALK_LEFT]);
		}
		else if (DIR_S || DIR_DOWN)
		{
			main->y += MOVE;
			main->img = mlx_texture_to_image(main->mlx, main->charactere[WALK_RIGHT]);
		}
		else if (DIR_A || DIR_LEFT)
		{
			main->x -= MOVE;
			main->img = mlx_texture_to_image(main->mlx, main->charactere[WALK_UP]);
		}
		else if (DIR_D || DIR_RIGHT)
		{
			main->x += MOVE;
			main->img = mlx_texture_to_image(main->mlx, main->charactere[WALK_DOWN]);
		}
		mlx_resize_image(main->img, 100, 100);
		mlx_image_to_window(main->mlx, main->img, main->x, main->y);
	}
}
