/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:40:54 by leobarbo          #+#    #+#             */
/*   Updated: 2023/11/07 18:32:41 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}
	if (n == 0 || (*str1 == *str2))
		return (0);
	else
		return ((unsigned char)*str1 - (unsigned char)*str2);
}
