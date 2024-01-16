/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:37:15 by leobarbo          #+#    #+#             */
/*   Updated: 2023/11/06 13:44:05 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		idx;
	char	ch;

	ch = (char)c;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] != ch)
			idx++;
		else
			return ((char *)str + idx);
	}
	if (ch == '\0')
		return ((char *)str + idx);
	return (0);
}
