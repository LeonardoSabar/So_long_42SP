/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:13:53 by leobarbo          #+#    #+#             */
/*   Updated: 2023/11/06 07:59:01 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long int nbr)
{
	int	index;

	index = 0;
	if (nbr <= 0)
	{
		index++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		index++;
		nbr /= 10;
	}
	return (index);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nlen;
	long	ln;

	ln = n;
	nlen = ft_intlen(ln);
	str = ft_calloc(nlen + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (ln == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (ln < 0)
	{
		str[0] = '-';
		ln = -ln;
	}
	while (nlen >= 1 && ln != 0)
	{
		str[--nlen] = ln % 10 + '0';
			ln /= 10;
	}
	return (str);
}
