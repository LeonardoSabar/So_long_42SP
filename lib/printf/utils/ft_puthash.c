/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:06:21 by leobarbo          #+#    #+#             */
/*   Updated: 2023/12/07 15:12:03 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_puthash(const char *format, long int idx, va_list ap)
{
	long long	value;

	value = (long long)va_arg(ap, unsigned int);
	if (value == 0)
		return (ft_putchar('0'));
	if (format[idx] == 'x')
		return (ft_putstr("0x") + ft_puthex(value, LOWER_HEX));
	else if (format[idx] == 'X')
		return (ft_putstr("0X") + ft_puthex(value, UPPER_HEX));
	else
		return (ft_putchar('0'));
}
