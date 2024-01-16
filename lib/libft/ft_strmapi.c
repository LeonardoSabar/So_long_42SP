/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:31:58 by leobarbo          #+#    #+#             */
/*   Updated: 2023/11/09 11:49:47 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	idx;
	char	*str_final;

	s_len = ft_strlen(s);
	idx = 0;
	str_final = (char *)ft_calloc(s_len + 1, sizeof(char));
	if (!str_final)
		return (NULL);
	while (s[idx])
	{
		str_final[idx] = f(idx, s[idx]);
		idx++;
	}
	return (str_final);
}
