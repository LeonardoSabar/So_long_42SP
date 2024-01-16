/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:07:48 by leobarbo          #+#    #+#             */
/*   Updated: 2023/11/04 10:19:34 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *str, char c)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[idx])
	{
		while (str[idx] == c)
			idx++;
		if (str[idx])
		{
			count++;
			while ((str[idx]) && (str[idx] != c))
				idx++;
		}
	}
	return (count);
}

static int	size_word(char *str, char letter)
{
	int	result;
	int	idx;

	idx = 0;
	if (!str)
		return (0);
	result = 0;
	while (str[idx] && str[idx] != letter)
	{
		result++;
		idx++;
	}
	return (result);
}

static char	*ft_cpy(char *str, char delimiter)
{
	size_t	s_word;
	char	*s;
	int		idx;
	int		idx_a;

	if (!str)
		return (NULL);
	idx = 0;
	idx_a = 0;
	s = NULL;
	s_word = size_word(str + idx, delimiter);
	s = malloc((s_word + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (str[idx] && str[idx] != delimiter)
		s[idx_a++] = str[idx++];
	s[idx_a] = '\0';
	return (s);
}

static void	putwords(const char *s, char c, char **matrix, int words_count)
{
	char	*next_str;
	int		idx;

	idx = 0;
	next_str = (char *)s;
	while (idx < words_count)
	{
		while (*next_str == c)
			next_str++;
		matrix[idx] = ft_cpy(next_str, c);
		if (!matrix[idx])
		{
			while (idx-- > 0)
				free(matrix[idx]);
			free(matrix);
			return ;
		}
		next_str += size_word(next_str, c) + 1;
		idx++;
	}
	matrix[words_count] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		words_count;

	if (!s)
		return (NULL);
	words_count = ft_countwords(s, c);
	matrix = malloc(sizeof(char *) * (words_count + 1));
	if (!matrix)
		return (NULL);
	putwords(s, c, matrix, words_count);
	return (matrix);
}
