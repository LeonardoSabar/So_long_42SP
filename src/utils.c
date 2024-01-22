/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:30:48 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/22 20:06:26 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	start_pos(t_main *game)
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
