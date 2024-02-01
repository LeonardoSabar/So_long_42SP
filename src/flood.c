/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:21:03 by leobarbo          #+#    #+#             */
/*   Updated: 2024/02/01 14:15:59 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(t_main *game, int y, int x)
{
	int	*size;

	size = ft_size_map(game->map_copy);
	if ((x > 0 && y > 0 && x < size[0] && y < size[1]
			&& game->map_copy[y][x] != '1' && game->map_copy[y][x] != 'V'
			&& game->map_copy[y][x] != 'X'))
	{
		game->map_copy[y][x] = 'X';
		ft_flood_fill(game, y + 1, x);
		ft_flood_fill(game, y - 1, x);
		ft_flood_fill(game, y, x + 1);
		ft_flood_fill(game, y, x - 1);
	}
	free(size);
}

int	ft_check_flood_fill(char **map)
{
	int	idx;
	int	odx;

	idx = 0;
	while (map[idx])
	{
		odx = 0;
		while (map[idx][odx])
		{
			if (map[idx][odx] == 'C' || map[idx][odx] == 'E'
				|| map[idx][odx] == 'P')
				return (FALSE);
			odx++;
		}
		idx++;
	}
	return (TRUE);
}

int	ft_valid_path(t_main *game, char *fd)
{
	game->map_copy = ft_read_map(fd);
	ft_flood_fill(game, game->char_pos_y / 64, game->char_pos_x / 64);
	if (ft_check_flood_fill(game->map_copy) == FALSE)
	{
		ft_free_map(game->map_copy);
		return (ft_putstr_fd(NO_PATH_MSG, 2), FALSE);
	}
	ft_free_map(game->map_copy);
	return (TRUE);
}
