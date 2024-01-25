/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:10:00 by leobarbo          #+#    #+#             */
/*   Updated: 2024/01/25 09:07:36 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_extension(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (file[i] == 'r' && file[i - 1] == 'e'
		&& file[i - 2] == 'b' && file[i - 3] == '.')
		return (TRUE);
	return (FALSE);
}

static char	*ft_read_all(int fd)
{
	int		chars_readed;
	char	*temp_buffer;
	char	*file_string;
	char	*aux;

	chars_readed = 1;
	temp_buffer = (char *) malloc((BUFFER_SIZE + 1));
	if (!temp_buffer)
		return (0);
	file_string = ft_strdup("");
	while (chars_readed > 0)
	{
		chars_readed = read(fd, temp_buffer, BUFFER_SIZE);
		temp_buffer[chars_readed] = '\0';
		aux = file_string;
		file_string = ft_strjoin(file_string, temp_buffer);
		free(aux);
	}
	free(temp_buffer);
	return (file_string);
}

char	**ft_read_map(char *map_content)
{
	int		fd;
	char	*temp_map;
	char	**map;
	int		count;


	count = 0;
	temp_map = NULL;
	fd = open(map_content, O_RDONLY);
	if (fd < 0)
	{
		free(temp_map);
		return (0);
	}
	temp_map = ft_read_all(fd);
	map = ft_split(temp_map, '\n');
	free(temp_map);
	close(fd);
	return (map);
}
