/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:16:49 by leobarbo          #+#    #+#             */
/*   Updated: 2023/11/04 09:44:08 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	idx;

	idx = 0;
	if (dest == NULL || src == NULL || (dest > src && dest < (src + n)))
		return (ft_memmove(dest, src, n));
	while (idx < n)
	{
		((unsigned char *)dest)[idx] = ((unsigned char *)src)[idx];
		idx++;
	}
	return (dest);
}
