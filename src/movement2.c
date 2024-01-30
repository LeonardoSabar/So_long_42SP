/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:24:37 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/30 16:47:28 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_action_key(mlx_key_data_t keydata, t_main *game)
{
	mlx_delete_image(game->mlx, game->img);
	mlx_delete_image(game->mlx, game->images[IMG_INICIAL]);
	game->img = mlx_texture_to_image
		(game->mlx, game->characteres[INICIAL]);
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		ft_move_up(game);
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		ft_move_down(game);
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		ft_move_left(game);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		ft_move_right(game);
	mlx_image_to_window(game->mlx, game->img,
		game->char_pos_x, game->char_pos_y);
}

void	ft_release_key(t_main *game)
{
	ft_put_moves(game);
	mlx_delete_image(game->mlx, game->img);
	if (game->last_state == WALK_LEFT)
		game->img = mlx_texture_to_image
			(game->mlx, game->characteres[INICIAL2]);
	else
		game->img = mlx_texture_to_image
			(game->mlx, game->characteres[INICIAL]);
	mlx_image_to_window(game->mlx, game->img,
		game->char_pos_x, game->char_pos_y);
}

void	ft_put_moves(t_main *game)
{
	char	*str;

	mlx_delete_image(game->mlx, game->strimage);
	str = ft_itoa(game->moves);
	ft_putnbr_fd(game->moves, 1);
	if (game->moves <= 0)
		ft_putstr_fd("  Move\n", 1);
	if (game->moves > 0)
		ft_putstr_fd("  Moves\n", 1);
	game->strimage = mlx_put_string(game->mlx, str, -1, -1);
	mlx_resize_image(game->strimage, 32, 32);
	mlx_image_to_window(game->mlx, game->strimage, 0, 0);

	// mlx_string_put(game->mlx, game->img, 64, game->height_tile * 64, 0x00FFFFFF, str);
	free(str);
}
