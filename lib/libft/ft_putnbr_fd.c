/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:29:12 by leobarbo          #+#    #+#             */
/*   Updated: 2023/11/06 16:59:01 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		result;

	nb = n;
	if (nb < 0)
	{
		write (fd, "-", 1);
		nb = -nb;
	}
	if (nb < 10)
	{
		result = nb + '0';
		write(fd, &result, 1);
		return ;
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	result = nb % 10 + '0';
	write(fd, &result, 1);
}
