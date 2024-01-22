/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:14:16 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/22 19:44:44 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	screen_resize(t_main *game)
{
	int	map_width;
	int	map_height;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	map_width = 0;
	map_height = 0;
	while (game->map[0][map_width])
		map_width++;
	while (game->map[map_height])
		map_height++;
	game->width_tile = 64;
	game->height_tile = 64;
	game->mlx = mlx_init(map_width * 64, map_height * 64, "so_long", true);
	if (!game->mlx)
		exit(EXIT_FAILURE);
}

int	game_init(t_main *game)
{
	screen_resize(game);
	get_textures(game);
	get_images(game);
	start_pos(game);
	draw_elements(game);
	count_collectible(game);
	mlx_put_string(game->mlx, "MOVEMENTS: ", 0, 0);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_main	main;

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
	mlx_key_hook(main.mlx, movement, &main);
	mlx_loop(main.mlx);
	mlx_terminate(main.mlx);
	return (EXIT_SUCCESS);
}
