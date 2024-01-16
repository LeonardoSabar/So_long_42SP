/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:07:00 by leobarbo          #+#    #+#             */
/*   Updated: 2023/10/20 15:35:05 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{	
	if (!(dest || src))
		return (NULL);
	if ((char *)dest < (char *)src)
		return (ft_memcpy(dest, src, n));
	while (n--)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}
