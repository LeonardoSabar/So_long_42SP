/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:14:16 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/16 16:19:32 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void error(void)
// {
// 	puts(mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }


void	hook(void* param)
{
	t_main* main;

	main = param;
	if (mlx_is_key_down(main->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(main->mlx);

}

int	main(int argc, char **argv)
{
	mlx_t*	mlx;
	t_main	main;
	t_game	game;

	if (argc != 2)
		return (EXIT_FAILURE);
	if (check_extension(argv[1]) == FALSE)
		return (EXIT_FAILURE);
	game.map = read_map(argv[1]);
	if (!game.map)
		return (EXIT_FAILURE);
	if (check_map(game.map) == FALSE)
	{
		free (game.map);
		return (EXIT_FAILURE);
	}
	mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		exit(EXIT_FAILURE);

	main.charactere[INCIAL] = mlx_load_png("images/cha.png");
	main.charactere[WALK_LEFT] = mlx_load_png("images/cha1.png");
	main.charactere[WALK_RIGHT] = mlx_load_png("images/cha2.png");
	main.charactere[WALK_UP] = mlx_load_png("images/cha3.png");
	main.charactere[WALK_DOWN] = mlx_load_png("images/cha4.png");
	// if (!texture)
    //     error();
	main.img = mlx_texture_to_image(mlx, main.charactere[INCIAL]);
	// if (!main.img)
    //     error();
	mlx_resize_image(main.img, 100, 100);
	mlx_image_to_window(mlx, main.img, 0, 0);

	main.mlx = mlx;
	main.x = 0;
	main.y = 0;

	mlx_loop_hook(mlx, &hook, &main);
	mlx_key_hook(mlx, &movement, &main);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
