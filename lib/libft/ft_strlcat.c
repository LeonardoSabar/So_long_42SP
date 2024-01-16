/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:59:27 by leobarbo          #+#    #+#             */
/*   Updated: 2023/11/07 18:32:16 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	idx;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	idx = 0;
	while (src[idx] && dest_len + idx + 1 < size)
	{
		dest[dest_len + idx] = src[idx];
		idx++;
	}
	dest[dest_len + idx] = '\0';
	if (size < dest_len)
		return (src_len + size);
	else
		return (src_len + dest_len);
}
