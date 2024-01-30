/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:14:16 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/30 20:02:44 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_screen_resize(t_main *game)
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

int	ft_game_init(t_main *game)
{
	ft_screen_resize(game);
	ft_count_collectible(game);
	ft_get_textures(game);
	mlx_set_icon(game->mlx, game->icon);
	mlx_delete_texture(game->icon);
	ft_get_images(game);
	ft_draw_elements(game);
	ft_put_moves(game);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_main	main;

	if (argc != 2)
		return (ft_putstr_fd(PARAMETERS_MSG, 2), EXIT_FAILURE);
	if (ft_check_extension(argv[1]) == FALSE)
		return (ft_putstr_fd(EXTENSION_MSG, 2), EXIT_FAILURE);
	ft_bzero(&main, sizeof(t_main));
	main.map = ft_read_map(argv[1]);
	if (!main.map)
		return (EXIT_FAILURE);
	if (ft_validation_map(main.map) == FALSE)
		return (ft_free_map(main.map), EXIT_FAILURE);
	ft_start_pos(&main);
	if (ft_valid_path(&main, argv[1]) == FALSE)
		return (ft_free_map(main.map), EXIT_FAILURE);
	if (ft_game_init(&main) == FALSE)
		return (1);
	mlx_key_hook(main.mlx, ft_movement, &main);
	mlx_loop(main.mlx);
	ft_free_map(main.map);
	ft_free_texture(&main);
	mlx_terminate(main.mlx);
	return (EXIT_SUCCESS);
}
