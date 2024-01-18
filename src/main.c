/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:14:16 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/16 20:24:43 by leobarbo         ###   ########.fr       */
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
	t_game* game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);

}

int	game_init(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	get_textures(game);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_main	main;
	t_game	game;

	if (argc != 2)
		return (EXIT_FAILURE);
	if (check_extension(argv[1]) == FALSE)
	{
		ft_printf(PARAMETERS_MSG, 1);
		return (EXIT_FAILURE);
	}
	game.map = read_map(argv[1]);
	if (!game.map)
		return (EXIT_FAILURE);
	if (check_map(game.map) == FALSE)
	{
		free (game.map);
		return (EXIT_FAILURE);
	}
	if (game_init(&game) == FALSE)
		return (1);
		
	main.x = 0;
	main.y = 0;

	mlx_loop_hook(game.mlx, hook, &game);
	mlx_key_hook(game.mlx, movement, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
