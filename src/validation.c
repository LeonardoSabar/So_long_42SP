/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:36:02 by leobarbo          #+#    #+#             */
/*   Updated: 2024/02/01 12:48:10 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_empty_map(char **map)
{
	if (map[0])
		return (TRUE);
	else
		return (FALSE);
}

int	ft_rectangle_map(char **map)
{
	size_t	len;
	int		idx;

	len = ft_strlen(map[0]);
	idx = 1;
	while (map[idx])
	{
		if (len != ft_strlen(map[idx]))
			return (FALSE);
		else
			idx++;
	}
	return (TRUE);
}

int	ft_check_elements(char **map)
{
	int	idx;
	int	odx;

	idx = 0;
	while (map[idx])
	{
		odx = 0;
		while (map[idx][odx])
		{
			if (!(map[idx][odx] == '1' || map[idx][odx] == '0'
				|| map[idx][odx] == 'C' || map[idx][odx] == 'E'
				|| map[idx][odx] == 'P' || map[idx][odx] == 'V'))
				return (FALSE);
			else
				odx++;
		}
		idx++;
	}
	return (TRUE);
}

int	ft_wall_check(char **map)
{
	size_t	idx;
	size_t	len;
	size_t	size_line;

	len = 0;
	idx = 0;
	while (map[len + 1])
		len++;
	size_line = ft_strlen(map[0]) - 1;
	while (idx <= size_line)
	{
		if (map[0][idx] != '1' || map[len][idx] != '1')
			return (FALSE);
		idx++;
	}
	idx = 0;
	while (idx < len)
	{
		if (map[idx][0] != '1' || map[idx][size_line] != '1')
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

int	ft_validation_map(char **map)
{
	if (ft_empty_map(map) == FALSE)
		return (ft_putstr_fd(EMPTY_MSG, 2), FALSE);
	if (ft_rectangle_map(map) == FALSE)
		return (ft_putstr_fd(RECTANGLE_MSG, 2), FALSE);
	if (ft_check_elements(map) == FALSE)
		return (ft_putstr_fd(ELEMENTS_MSG, 2), FALSE);
	if (ft_wall_check(map) == FALSE)
		return (ft_putstr_fd(WALL_MSG, 2), FALSE);
	if (ft_count_exit(map) == FALSE)
		return (ft_putstr_fd(NUMBER_EXIT_MSG, 2), FALSE);
	if (ft_count_player(map) == FALSE)
		return (ft_putstr_fd(NUMBER_PLAYER_MSG, 2), FALSE);
	if (ft_zero_collectible(map) == FALSE)
		return (ft_putstr_fd(NO_COLLECTIBLE_MSG, 2), FALSE);
	return (TRUE);
}
