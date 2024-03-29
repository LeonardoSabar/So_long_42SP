/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:23:26 by leobarbo          #+#    #+#             */
/*   Updated: 2024/02/01 18:45:41 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_pick_collectibles(t_main *game)
{
	int	idx;
	int	odx;

	idx = 0;
	while (game->map[idx])
	{
		odx = 0;
		while (game->map[idx][odx])
		{
			if (game->map[game->char_pos_y / 64][game->char_pos_x / 64] == 'C')
			{
				(game->map[game->char_pos_y / 64][game->char_pos_x / 64] = '0');
				ft_draw_base_map(game);
				game->collectible--;
				return ;
			}
			odx++;
		}
		idx++;
	}
}

void	ft_count_collectible(t_main *game)
{
	int	idx;
	int	odx;

	game->collectible = 0;
	idx = 0;
	while (game->map[idx])
	{
		odx = 0;
		while (game->map[idx][odx])
		{
			if (game->map[idx][odx] == 'C')
				game->collectible++;
			odx++;
		}
		idx++;
	}
}

int	ft_zero_collectible(char **game)
{
	int	idx;
	int	odx;
	int	collectible;

	collectible = 0;
	idx = 0;
	while (game[idx])
	{
		odx = 0;
		while (game[idx][odx])
		{
			if (game[idx][odx] == 'C')
				collectible++;
			odx++;
		}
		idx++;
	}
	if (collectible == 0)
		return (FALSE);
	return (TRUE);
}
