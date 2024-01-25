/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:30:48 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/25 18:05:11 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

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
				game->x = odx * 64;
				game->y = idx * 64;
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
