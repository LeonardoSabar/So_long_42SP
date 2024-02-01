/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:14:39 by leobarbo          #+#    #+#             */
/*   Updated: 2023/12/08 11:59:47 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int		num1;
	int		num2;
	int		num3;
	int		ret;

	num1 = 42;
	num2 = 99;
	num3 = 0;

	// ret = ft_printf("%d", 42);
	// printf("\n\n%d\n\n", ret);
	// ret = ft_printf("%d", 42);
	// ft_printf("\n\n%d\n\n", ret);

	// ret = ft_printf("%+d", -42);
	// ft_printf("\n\n%d\n\n", ret);
	// ret = printf("%d", -42);
	// printf("\n\n%d\n\n", ret);

	// printf("O ponteiro será: %p\n", &num1);
	// ft_printf("O ponteiro será: %p\n", &num1);

	// ft_printf("%         d", 42);
	// printf("%         d", 42);

	printf("%#u\n", 42);
	ft_printf("%#u\n", 42);
	printf("%+u\n", 42);
	ft_printf("%+u\n", 42);
	return (0);
}
