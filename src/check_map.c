/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:36:02 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/16 20:24:09 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int empty_map(char **map)
{
	if (map[0])
		return (TRUE);
	else
		return (FALSE);
}

int rectangle_map(char **map)
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
int	wrong_map(char **map)
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
				|| map[idx][odx] == 'P'))
				return (FALSE);
			else
				odx++;
		}
		idx++;
	}
	return (TRUE);
}
int	wall_map(char **map)
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
int check_map(char **map)
{
	if (empty_map(map) == FALSE)
	{
		ft_printf(EMPTY_MSG, 1);
		return (FALSE);
	}
	if (rectangle_map(map) == FALSE)
	{
		ft_printf(RECTANGLE_MSG, 1);
		return (FALSE);
	}
	if (wrong_map(map) == FALSE)
	{
		ft_printf(ELEMENTS_MSG, 1);
		return (FALSE);
	}
	if (wall_map(map) == FALSE)
	{
		ft_printf(WALL_MSG);
		return (FALSE);
	}
	return (TRUE);
}
