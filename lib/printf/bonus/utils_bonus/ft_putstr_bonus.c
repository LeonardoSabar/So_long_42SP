/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:43:51 by leobarbo          #+#    #+#             */
/*   Updated: 2023/12/02 16:12:51 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

int	ft_putstr(char *s)
{
	int	idx;

	idx = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	idx = ft_strlen(s);
	write(1, s, idx);
	return (idx);
}
