/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:30:48 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/20 11:45:53 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	start_pos(t_main *game)
{
	int	idx;
	int	odx;

	idx = 0;
	while (game->map[idx])
	{
		odx = 0;
		while (game->map[idx][odx])
		{
			if (game->map[idx][odx] == 'P')
			{
				game->x = odx * 64;
				game->y = idx * 64;
				return ;
			}
			odx++;
		}
		idx++;
	}
}

void	pick_collectables(t_main *game)
{
	int	idx;
	int	odx;

	idx = 0;
	while (game->map[idx])
	{
		odx = 0;
		while (game->map[idx][odx])
		{
			if (game->map[game->y / 64][game->x / 64] == 'C')
			{
				(game->map[game->y / 64][game->x / 64] = '0');
				draw_elements(game);
				game->collectable--;
				return ;
			}
			odx++;
		}
		idx++;
	}
}
void	count_collectable(t_main *game)
{
	int	idx;
	int	odx;

	pick_collectables(game);
	idx = 0;
	while (game->map[idx])
	{
		odx = 0;
		while (game->map[idx][odx])
		{
			if (game->map[idx][odx] == 'C')
				game->collectable++;
			odx++;
		}
		idx++;
	}
}
