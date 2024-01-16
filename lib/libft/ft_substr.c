/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:36:57 by leobarbo          #+#    #+#             */
/*   Updated: 2023/11/04 08:25:03 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	char	*substr;
	size_t	idx;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	idx = 0;
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	while (idx < len && s[start] != '\0')
	{
		substr[idx] = s[start];
		start++;
		idx++;
	}	
	substr[idx] = '\0';
	return (substr);
}
