/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:41:41 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/16 20:03:05 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_game *game)
{
	game->main = ft_calloc(1, sizeof(t_main));
	game->main->charactere[INCIAL] = mlx_load_png("./images/cha.png");
	game->main->charactere[WALK_LEFT] = mlx_load_png("./images/cha1.png");
	game->main->charactere[WALK_RIGHT] = mlx_load_png("./images/cha2.png");
	game->main->charactere[WALK_UP] = mlx_load_png("./images/cha3.png");
	game->main->charactere[WALK_DOWN] = mlx_load_png("./images/cha4.png");
}
