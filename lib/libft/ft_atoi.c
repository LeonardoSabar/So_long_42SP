/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:37:53 by leobarbo          #+#    #+#             */
/*   Updated: 2023/11/07 09:51:55 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_atoi(const char *str)
{
	int		value;
	int		idx;
	int		h;

	value = 0;
	idx = 0;
	h = 1;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '-')
	{
		h = -1;
		idx++;
	}
	else if (str[idx] == '+')
		idx++;
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		value = (value * 10) + (str[idx] - '0');
		idx++;
	}
	value = value * h;
	return (value);
}
