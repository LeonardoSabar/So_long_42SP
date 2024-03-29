/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:59:34 by leobarbo          #+#    #+#             */
/*   Updated: 2023/12/07 15:12:40 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strrchr(const char *str, int ch)
{
	const char	*last_ch;

	ch = ch % 256;
	last_ch = ((void *)0);
	while (*str)
	{
		if (*str == ch)
			last_ch = str;
		str++;
	}
	if (ch == '\0')
		return ((char *)str);
	return ((char *)last_ch);
}
