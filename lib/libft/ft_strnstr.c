/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:51:33 by leobarbo          #+#    #+#             */
/*   Updated: 2023/11/02 11:41:22 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	char	*h;
	char	*n;
	size_t	l;

	if (*substr == 0)
		return ((char *)str);
	n = (char *)substr;
	while (*str && len > 0)
	{
		h = (char *)str;
		l = len;
		while (*str && *substr && *str == *substr && len-- > 0)
		{
			str++;
			substr++;
		}
		if (!*substr)
			return (h);
		str = ++h;
		substr = n;
		len = --l;
	}
	return (NULL);
}
