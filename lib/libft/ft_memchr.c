/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:37:40 by leobarbo          #+#    #+#             */
/*   Updated: 2023/10/21 11:48:39 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				idx;
	const unsigned char	*us;

	us = (const unsigned char *)s;
	idx = 0;
	while (idx < n)
	{
		if (us[idx] == (unsigned char)c)
			return ((void *)(us + idx));
		idx++;
	}
	return (NULL);
}
