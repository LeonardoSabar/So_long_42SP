/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:41:00 by leobarbo          #+#    #+#             */
/*   Updated: 2023/12/08 09:31:28 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_bonus_arg(const char *format, long int idx, va_list ap)
{
	if (format[idx] == '#')
		return (ft_puthash(format, idx + 1, ap));
	if (format[idx] == '+')
		return (ft_putsign(format, idx + 1, ap));
	return (0);
}

int	args_build(const char *format, va_list ap)
{
	long int	idx;
	long int	ret;

	ret = 0;
	idx = 0;
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			if ((ft_strrchr("#+", format[idx + 1])))
			{
				ret += ft_bonus_arg(format, idx++ + 1, ap);
				while ((ft_strrchr("#+", format[idx])) != NULL)
				idx++;
			}
			else
				ret += ft_printf_arg(format, idx++, ap);
		}
		else
			ret += ft_putchar(format[idx]);
		idx++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	long int	ret;

	ret = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	ret = args_build(&*format, ap);
	va_end(ap);
	return (ret);
}
