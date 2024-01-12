/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:14:16 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/12 12:25:20 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static mlx_image_t	*g_img;
static mlx_image_t	*g_img1;

void	hook(void* param)
{
	t_main* main;

	main = param;
	if (mlx_is_key_down(main->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(main->mlx);

}

int32_t	main(void)
{
	mlx_t*	mlx;
	t_main	main;

	mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		exit(EXIT_FAILURE);

	main.texture0 = mlx_load_png("images/cha.png");
	main.texture1 = mlx_load_png("images/cha1.png");
	main.texture2 = mlx_load_png("images/cha2.png");
	main.texture3 = mlx_load_png("images/cha3.png");
	main.texture4 = mlx_load_png("images/cha4.png");
	// if (!texture)
    //     error();
	g_img = mlx_texture_to_image(mlx, main.texture0);
	// if (!g_img)
    //     error();
	mlx_resize_image(g_img, 100, 100);
	mlx_image_to_window(mlx, g_img, 0, 0);

	main.mlx = mlx;
	main.img = g_img;
	main.x = 0;
	main.y = 0;

	mlx_loop_hook(mlx, &hook, &main);
	mlx_key_hook(mlx, &movement, &main);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
