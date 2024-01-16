/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 08:24:47 by leobarbo          #+#    #+#             */
/*   Updated: 2023/10/23 11:40:30 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str1_len;
	size_t	str2_len;
	size_t	str_result_len;
	char	*str_result;

	if (!s1 || !s2)
		return (NULL);
	str1_len = ft_strlen(s1);
	str2_len = ft_strlen(s2);
	str_result_len = (str1_len + str2_len);
	str_result = (char *)malloc (sizeof(char) * (str_result_len + 1));
	if (!str_result)
		return (NULL);
	ft_strlcpy(str_result, s1, str1_len + 1);
	ft_strlcat(str_result, s2, str_result_len + 1);
	str_result_len = '\0';
	return (str_result);
}
