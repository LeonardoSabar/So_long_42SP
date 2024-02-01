/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:16:34 by leobarbo          #+#    #+#             */
/*   Updated: 2023/12/07 12:17:25 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

int	ft_putsign(const char *format, long int idx, va_list ap)
{
	long long	value;

	value = (long long)va_arg(ap, int);
	while (format[idx] == '+')
		idx++;
	if (format[idx] == 'd' || format[idx] == 'i')
	{
		if (value < 0)
			return (ft_putnbr(value));
		return (ft_putchar('+') + ft_putnbr(value));
	}
	return (0);
}
