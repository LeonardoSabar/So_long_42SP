/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:18:18 by leobarbo          #+#    #+#             */
/*   Updated: 2023/12/04 17:18:32 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

int	ft_printf_arg(const char *format, long int idx, va_list ap)
{
	if (format[idx + 1] == '%')
		return (ft_putchar(format[idx + 1]));
	else if (format[idx + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format[idx + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format[idx + 1] == 'd' || format[idx + 1] == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format[idx + 1] == 'u')
		return (ft_putnbr_unsg(va_arg(ap, t_unsgi)));
	else if (format[idx + 1] == 'x')
		return (ft_puthex(va_arg(ap, t_unsgi), LOWER_HEX));
	else if (format[idx + 1] == 'X')
		return (ft_puthex(va_arg(ap, t_unsgi), UPPER_HEX));
	else if (format[idx + 1] == 'p')
		return (ft_putpointer(va_arg(ap, void *), LOWER_HEX));
	else
		return (0);
}
