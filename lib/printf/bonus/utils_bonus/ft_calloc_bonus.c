/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:29:06 by leobarbo          #+#    #+#             */
/*   Updated: 2023/12/02 16:12:15 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

void	*ft_calloc(size_t nmemb, size_t n)
{
	void	*ptr;

	ptr = malloc(nmemb * n);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * n);
	return (ptr);
}
