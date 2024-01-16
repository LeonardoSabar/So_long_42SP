/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:10:00 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/16 17:03:45 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (file[i] == 'r' && file[i - 1] == 'e'
		&& file[i - 2] == 'b' && file[i - 3] == '.')
		return (TRUE);
	return (FALSE);
}

char	**read_map(char *map_content)
{
	int		fd;
	char	*temp_map;
	char	**map;
	int		count;

	count = 0;
	temp_map = ft_calloc(BUFFER + 1, sizeof(char *));
	if (!temp_map)
		return (0);
	fd = open(map_content, O_RDONLY);
	if (fd < 0)
	{
		free(temp_map);
		return (0);
	}
	count = read(fd, temp_map, BUFFER);
	if (count <= 0)
	{
		free(temp_map);
		return (0);
	}
	map = ft_split(temp_map, '\n');
	free(temp_map);
	close(fd);
	return (map);
}
