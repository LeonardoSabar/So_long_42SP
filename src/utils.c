/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:30:48 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/29 18:17:49 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	ft_free_map(char **map)
{
	int	idx;

	idx = 0;
	while (map[idx])
	{
		free(map[idx]);
		idx++;
	}
	free(map);
}

int	*ft_size_map(char **map)
{
	int	*size;
	int	height;
	int	width;

	height = 0;
	size = 0;
	size = malloc(sizeof(int) * 2);
	if (!size)
		return (NULL);
	while (map[height])
	{
		width = 0;
		while (map[height][width])
			width++;
		height++;
	}
	size[0] = width;
	size[1] = height;
	return (size);
}


void	ft_struct_inicialize(t_main *game)
{
	ft_bzero(game, sizeof(t_main));
	// game->mlx = NULL;
	// game->map = NULL;
	// game->img = NULL;
	// game->width_tile = 0;
	// game->height_tile = 0;
	// game->char_pos_x = 0;
	// game->char_pos_y = 0;
	// game->moves = 0;
	// game->collectible = 0;
}


void	ft_start_pos(t_main *game)
{
	int	idx;
	int	odx;

	game->last_state = INICIAL;
	idx = 0;
	while (game->map[idx])
	{
		odx = 0;
		while (game->map[idx][odx])
		{
			if (game->map[idx][odx] == 'P')
			{
				game->char_pos_x = odx * 64;
				game->char_pos_y = idx * 64;
				return ;
			}
			odx++;
		}
		idx++;
	}
}

int	ft_count_player(char **game)
{
	int	idx;
	int	odx;
	int	player;

	player = 0;
	idx = 0;
	while (game[idx])
	{
		odx = 0;
		while (game[idx][odx])
		{
			if (game[idx][odx] == 'P')
				player++;
			odx++;
		}
		idx++;
	}
	if (player != 1)
		return (FALSE);
	return (TRUE);
}
