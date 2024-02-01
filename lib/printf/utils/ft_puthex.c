/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:34:05 by leobarbo          #+#    #+#             */
/*   Updated: 2023/12/07 15:12:09 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	count_hex(t_unsgi n)
{
	int	idx;

	idx = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		idx++;
	}
	return (idx);
}

static char	*hex_to_str(t_unsgi nbr, char *base)
{
	int		size;
	char	*hex;

	size = count_hex(nbr);
	hex = malloc(sizeof(char) * (size + 1));
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (size > 0)
	{
		hex[size-- - 1] = base[nbr % 16];
		nbr = nbr / 16;
	}
	return (hex);
}

int	ft_puthex(t_unsgi nbr, char *base)
{
	char	*str;
	int		len;

	str = hex_to_str(nbr, base);
	len = ft_putstr(str);
	free(str);
	return (len);
}
