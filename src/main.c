/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:14:16 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/19 12:43:02 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hook(void* param)
{
	t_main* game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);

}

int	game_init(t_main *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	get_textures(game);
	get_images(game);
	draw_elements(game);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_main	main;


	main.x = 64;
	main.y = 64;
	if (argc != 2)
		return (EXIT_FAILURE);
	if (check_extension(argv[1]) == FALSE)
	{
		ft_printf(PARAMETERS_MSG, 1);
		return (EXIT_FAILURE);
	}
	main.map = read_map(argv[1]);
	if (!main.map)
		return (EXIT_FAILURE);
	if (check_map(main.map) == FALSE)
	{
		free (main.map);
		return (EXIT_FAILURE);
	}
	if (game_init(&main) == FALSE)
		return (1);

	mlx_loop_hook(main.mlx, hook, &main);
	mlx_key_hook(main.mlx, movement, &main);
	mlx_loop(main.mlx);
	mlx_terminate(main.mlx);
	return (EXIT_SUCCESS);
}
