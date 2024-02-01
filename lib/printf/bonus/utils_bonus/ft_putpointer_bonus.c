/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:58:34 by leobarbo          #+#    #+#             */
/*   Updated: 2023/12/02 16:12:48 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

static int	count_hex(t_unsgl nbr)
{
	int	idx;

	idx = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		idx++;
	}
	return (idx);
}

static char	*hex_to_str(t_unsgl nbr, char *base)
{
	int		size;
	char	*hex;

	if (!nbr)
		return (NULL);
	size = count_hex(nbr);
	hex = malloc(sizeof(char) * (size + 1));
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (size > 0)
	{
		hex[size - 1] = base[nbr % 16];
		nbr = nbr / 16;
		size--;
	}
	return (hex);
}

int	ft_putpointer(void *nbr, char *base)
{
	int		len;
	char	*str;
	t_unsgl	n;

	if (!nbr)
	{
		ft_putstr(NULL_POINTER);
		return (5);
	}
	n = (t_unsgl)nbr;
	str = hex_to_str(n, base);
	if (!str)
		return (-1);
	len = ft_putstr("0x") + ft_putstr(str);
	free(str);
	return (len);
}
