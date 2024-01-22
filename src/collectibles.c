/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:23:26 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/22 19:46:21 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	pick_collectibles(t_main *game)
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
				ft_printf("%d\n", game->collectable);
				return ;
			}
			odx++;
		}
		idx++;
	}
}

void	count_collectible(t_main *game)
{
	int	idx;
	int	odx;

	// pick_collectibles(game);
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
