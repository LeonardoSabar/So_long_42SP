/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:56:09 by leobarbo          #+#    #+#             */
/*   Updated: 2023/11/06 17:04:16 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*mutable_s;
	int		i;

	mutable_s = (char *)s;
	i = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(mutable_s) + 1));
	if (!ptr)
		return (NULL);
	while (*mutable_s)
		ptr[i++] = *mutable_s++;
	ptr[i] = '\0';
	return (ptr);
}
